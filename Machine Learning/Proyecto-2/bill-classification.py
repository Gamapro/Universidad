import numpy as np
import matplotlib.pyplot as plt
import seaborn as sb
import cv2
import pandas as pd

import torch
import torch.nn as nn
import torchvision.transforms as tt

from IPython.display import clear_output

def get_default_device():
    if torch.cuda.is_available(): return torch.device('cuda')
    else: return torch.device('cpu')

device = get_default_device()

def stackImages(scale,imgArray):
    rows = len(imgArray)
    cols = len(imgArray[0])
    rowsAvailable = isinstance(imgArray[0], list)
    width = imgArray[0][0].shape[1]
    height = imgArray[0][0].shape[0]
    if rowsAvailable:
        for x in range ( 0, rows):
            for y in range(0, cols):
                if imgArray[x][y].shape[:2] == imgArray[0][0].shape [:2]:
                    imgArray[x][y] = cv2.resize(imgArray[x][y], (0, 0), None, scale, scale)
                else:
                    imgArray[x][y] = cv2.resize(imgArray[x][y], (imgArray[0][0].shape[1], imgArray[0][0].shape[0]), None, scale, scale)
                if len(imgArray[x][y].shape) == 2: imgArray[x][y]= cv2.cvtColor( imgArray[x][y], cv2.COLOR_GRAY2BGR)
        imageBlank = np.zeros((height, width, 3), np.uint8)
        hor = [imageBlank]*rows
        hor_con = [imageBlank]*rows
        for x in range(0, rows):
            hor[x] = np.hstack(imgArray[x])
        ver = np.vstack(hor)
    else:
        for x in range(0, rows):
            if imgArray[x].shape[:2] == imgArray[0].shape[:2]:
                imgArray[x] = cv2.resize(imgArray[x], (0, 0), None, scale, scale)
            else:
                imgArray[x] = cv2.resize(imgArray[x], (imgArray[0].shape[1], imgArray[0].shape[0]), None,scale, scale)
            if len(imgArray[x].shape) == 2: imgArray[x] = cv2.cvtColor(imgArray[x], cv2.COLOR_GRAY2BGR)
        hor= np.hstack(imgArray)
        ver = hor
    return ver

class Classifier(nn.Module):

    def __init__(self, conv, dense, device, channels=3):
        super(Classifier, self).__init__()
        self.device = device
        self.channels = channels
        self.dim = channels
        convs, rests, linears = [],[],[]
        doble, same, fin = (4,2,1), (3,1,1), (4,1,0)
        for i in range(len(conv) - 1):
            convs.append(  self.ConvLayer( conv[i], conv[i+1], values=doble, pool=True) )
            rests.append(  self.RestLayer( conv[i+1]) )
        self.flatten = nn.Flatten()
        for i in range(len(dense) - 1):
            linears.append(self.LinearLayer(dense[i], dense[i+1], output=(i+2==len(dense))  ))
        self.conv_layers = nn.Sequential(*convs)
        self.rest_layers = nn.Sequential(*rests)
        self.linear_layers = nn.Sequential(*linears)

    def forward(self, x):
        for conv, rest in zip(self.conv_layers, self.rest_layers):
            x = conv(x)
            x = rest(x) + x
        x = self.flatten(x)
        for layer in self.linear_layers:
            x = layer(x)
        return x

    def LinearLayer(self, in_size, out_size, output=False):
        layers = [ nn.Linear(in_size, out_size, device=self.device) ]
        if not output:
            layers.extend( [nn.BatchNorm1d(out_size),
                            nn.ReLU(inplace=True)] )
        else:
            layers.append( nn.Softmax(dim=1) )
            
        return nn.Sequential( *layers )

    def ConvLayer(self, in_size, out_size, values=(3,1,1), pool=False, output=False, batch=True):
        kernel, stride, padding = values
        layers = [  nn.Conv2d(in_size, out_size, kernel_size=kernel, stride=stride, padding=padding, bias=False, device=self.device),
                    nn.BatchNorm2d(out_size), 
                    nn.ReLU(inplace=True)
        ]
        if pool:  layers.append( nn.MaxPool2d(2, 2) )
        return nn.Sequential(*layers)
        
    def RestLayer(self, size, values=(3,1,1)):
        return nn.Sequential( self.ConvLayer(size, size, values), self.ConvLayer(size, size, values))
        
def getPredArray(predi, classes):

    vals, d = [], dict()
    for i,x in enumerate(predi):
        cosa = [ classes[i] for _ in range(int(x*100) + 1) ]
        vals.extend( cosa )
    d['values'] = vals

    vals_df = pd.DataFrame(np.array([vals,vals]).T , columns=['values','other'])

    return vals, d, vals_df

def toDim(img, val=(512,512)):
    dim = val
    resized = cv2.resize(img, dim, interpolation = cv2.INTER_AREA)
    return resized

def stackTensors(input):
    input = torch.unsqueeze(input, 0)
    input = torch.concat( (input, input) , 0)
    return input

def processImg(img, dim=(512, 512)):

    resized = toDim(img, dim)

    resized = (resized - np.min(resized)) / (np.max(resized) - np.min(resized)) * 2 - 1

    input = torch.tensor(resized, dtype=torch.float32)
    input = torch.unsqueeze(torch.moveaxis(input, 2, 0), 0)
    input = torch.concat( (input, input) , 0)

    return input

normalized_stats = ((0.5, 0.5, 0.5), (0.5, 0.5, 0.5) )
dim = (256, 512)
# dim = (512, 512)
test_tfms = tt.Compose([
                        tt.ToPILImage(),    
                        tt.Resize(dim), 
                        tt.ToTensor(),
                        tt.Normalize(*normalized_stats,inplace=True)
])

classes = ['20', '100', '200', '50', '500']

def predict(img):

    input = test_tfms(img)
    input_copy = input.detach().numpy().copy()
    input = stackTensors(input)

    pred = model(input)
    predi = pred.detach().numpy().copy()
    _, pred = torch.max(pred, dim=1)
    s = classes[pred[0]]
    
    return predi, pred, s, input_copy

def rects(img):
  gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
  gray = cv2.GaussianBlur(gray, (5, 5), 0)

  ret, imgt = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY_INV)
  # ret, imgt = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)

  countours, hierarchy = cv2.findContours(imgt.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
  rectangles = [cv2.boundingRect(countour) for countour in countours]
  c = 0
  for rect in rectangles:
    if rect[2] > 50 and rect[3] > 50:
      imgn = img[rect[1]:rect[1] + rect[3], rect[0]:rect[0] + rect[2]]
      imgn = cv2.resize(imgn, (100, 100))
      c += 1

      # Clasificar la imagen imgn
      predi, pred, s, input_copy = predict(imgn)
      # Escribir el resultado

      cv2.rectangle(img, (rect[0], rect[1]), (rect[0] + rect[2], rect[1] + rect[3]), (255, 0, 0), 2)
      cv2.putText(img, s, (rect[0], rect[1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (200, 0, 0), 3, cv2.LINE_AA)
  return img, imgt





model = torch.load('../models/model-bills-3.0-95.pth', map_location=device)
# model = torch.load('../models/model-bills-3.0-swap.pth', map_location=device)
model.eval()

# Webcam
webcam = cv2.VideoCapture(0) # En lugar de ingresar la direccion del video, un numero para el id 

webcam.set(3,600)  # Set width, id 3
webcam.set(4,600)  # Set heigth, id 4
webcam.set(10,100)  # Set brillo, id 10

fig, ax = plt.subplots()

#sizeVideo = (int(webcam.get(3)) , int(webcam.get(4)) )
sizeVideo = (500, 500)
# videoRecorder = cv2.VideoWriter('videoBilletes.avi', cv2.VideoWriter_fourcc(*'MJPG'), 5, sizeVideo)

while True:
    success, img = webcam.read()

    img_ori = img.copy()
    img_rects = img.copy()
    
    predi, pred, s, input_copy = predict(img)
    
    img_rects, imgt = rects(img_rects)

    print(f'Predicciones {predi[0]}')
    print(s)

    predictions, dc, d2 = getPredArray(predi[0], classes)
    sb.countplot(x='values',data=d2, ax=ax)
    fig.savefig('hist.jpg')
    ax.clear()

    fig_img = cv2.imread("hist.jpg")
    imgs = stackImages(0.6, [[img_ori, fig_img], [img_rects, imgt]])
    
    # videoRecorder.write(cv2.resize(imgs, sizeVideo, interpolation = cv2.INTER_AREA))

    cv2.imshow("Video",imgs)
    
    clear_output(wait=True)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

plt.close()
webcam.release()           # Liberar la webcam
# videoRecorder.release()
cv2.destroyAllWindows()    # Limpiar las ventanas

