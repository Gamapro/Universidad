# %%
import numpy as np 
import matplotlib.pyplot as mpl
import random
import matplotlib._color_data as mcd
from random import shuffle
from collections import deque
import json

# %% [markdown]
# # Input format
# 
# - Number of terminals n
# - Capacity c and position(x, y) for each n terminals
# - Number of work stations m
# - Demand d and position(x, y) for each m work stations
# 
# <details>
# <summary>Example:</summary>
# <br>
# 10  <br>
# 5 54 28 <br> 
# 4 28 75  <br>
# 4 84 44  <br>
# 2 67 17  <br>
# 3 90 41  <br>
# 1 68 67  <br>
# 3 24 79  <br>
# 4 38 59  <br>
# 5 27 86  <br>
# 4 7 76  <br>
# 3  <br>
# 12 19 76 <br>  
# 14 50 30  <br>
# 13 23 79  <br>
# </details>
# 
# # State representation
# 
# Each state will be representated with an array of size N(Number of terminals) where each position will represent the workstation index, each index will be in a range from 0 to M(Number of workstations) - 1.

# %%
class Optimizator:

    def __init__(self, maxiter = 200, maxIterPreSA = 200):
        self.maxiter = maxiter
        self.maxIterPreSA = maxIterPreSA
        self.Capacity = []
        self.TerminalPos = []
        self.Demand = []
        self.WorkStationPos = []
        self.tabuMaxSize = 0
        self.tabuIncrement = 5
        self.ys = []

    def clear(self):
        self.ys = []
        self.tabuMaxSize = 0
        mpl.clf()

    # Graficar optimización
    def graph(self, save = False, filename = ""):
        mpl.plot([i for i in range(len(self.ys))], self.ys)
        if save:
            mpl.savefig(filename)

    # Calcular distancia
    def dist(self, a, b):
        return np.round(np.hypot(a[0] - b[0], a[1] - b[1]))    

    # Lectura
    def readinput(self, filename):
        file = open(filename)
        self.N = file.readline().strip()
        self.N = int(self.N)
        
        for i in range(self.N):
            c, x, y = file.readline().strip().split(' ')
            c, x, y = int(c), int(x), int(y)
            
            self.Capacity.append(c)
            self.TerminalPos.append((x, y))
        
        self.M = file.readline().strip()
        self.M = int(self.M)
        
        for i in range(self.M):
            d, x, y = file.readline().strip().split(' ')
            d, x, y = int(d), int(x), int(y)
            
            self.Demand.append(d)
            self.WorkStationPos.append((x, y))
        
        self.dists = np.zeros(shape=(self.N, self.M))
        
        for i in range(self.N):
            for j in range(self.M):
                self.dists[i][j] = self.dist(self.TerminalPos[i], self.WorkStationPos[j])

    # Imprime la suma de la capacidad y demanda
    def printDataSum(self):
        print(f'Capacity sum : {sum(self.Capacity)}')
        print(f'Demand sum : {sum(self.Demand)}')

    # Calcula las distancias a las estaciones
    def f(self, x):
        s = 0
        for i in range(len(x)):
            s += self.dists[i][x[i]]
        return s

    # Realiza la suma por cada estacion 
    def g(self, x):
        sums = [0 for i in range(self.M)]
        for i, ws in enumerate(x):
            sums[ws] += self.Capacity[i]
        res = 0
        for i in range(self.M):
            # Si se excede devuelde algo diferente de cero
            if sums[i] > self.Demand[i]:
                res+=1
                # res += sums[i] - self.Demand[i]
        return res

    def capacityDistribution(self, x):
        sums = [0 for i in range(self.M)]
        for i, ws in enumerate(x):
            sums[ws] += self.Capacity[i]
        return sums

    # Se modifica los vectores de forma aleatoria 
    # Se busca una solucion viable (problema de al mochila)
    def modifyVector(self, x):
        sums  = [ 0 for i in range(self.M)]
        cosas = [[] for i in range(self.M)]
        menor, mayor = [], []
        cost = []

        for i, ws in enumerate(x):
            sums[ws] += self.Capacity[i]
            cosas[ws].append(i)

        for i in range(self.M):
            if sums[i] > self.Demand[i]: 
                shuffle(cosas[i])
                mayor.append([cosas[i], i])
                cost.append(sums[i])
            else: 
                menor.append([cosas[i], i])

        tam = len(menor)
        for idx, (p, i) in enumerate(mayor):
            while cost[idx] > self.Demand[i]:
                elem = p.pop()
                cost[idx] -= self.Capacity[elem]
                idx2 = np.random.randint(0, tam)
                menor[idx2][0].append(elem)

        for p, i in mayor:
            for elem in p:
                x[elem] = i
        for p, i in menor:
            for elem in p:
                x[elem] = i

        return x

    # Recocido simulado num.1
    def getInitialSolution(self, debug = False): 
        
        x = [np.random.randint(0, self.M) for i in range(self.N)]
        temperature = 10000
        iter = 0
        gx = self.g(x)

        while gx != 0 and iter < 15000:

            newx = x.copy()
            newx = self.modifyVector(newx)
            gNewX = self.g(x)

            if debug: print(temperature, gx, np.exp((gx-gNewX)/temperature))   
            
            if(gNewX < gx):
                x = newx
                gx = gNewX
            elif temperature > 0 and np.random.uniform() < np.exp((gx-gNewX)/temperature):
                x = newx
                gx = gNewX
               
            temperature *= 0.999
            
            iter += 1
            
        if(self.g(x) != 0): 
            print("Initial state failed")
            return self.getInitialSolution(debug = debug)

        print("Initial state created")
        return x
    
    def isValidState(self, state):
        return self.g(state) == 0

    # Vecinos para la tabla tabu 
    def getNeighbors(self, state, reduce = False):
        neighbors = []
        
        for i in range(len(state)):

            if reduce and np.random.uniform() < 0.97: pass
            
            # Intercambiar i con j
            for j in range(i+1, len(state)):
                if(state[i] != state[j]):
                    newprospect = state.copy()
                    newprospect[i] = state[j]
                    newprospect[j] = state[i]
                    
                    if(self.isValidState(newprospect)):
                        neighbors.append(newprospect)
                
            # Mover i a otra workstation 
            for j in range(self.M):
                if(state[i] != j):
                    newprospect = state.copy()
                    newprospect[i] = j
                    if(self.isValidState(newprospect)):
                        neighbors.append(newprospect)
        
        return neighbors

    # Recocido simulado num. 2
    # Optimiza la solucion inicial
    def preSA(self, x, debug = False):
        temperature = 500
        maxIter = self.maxIterPreSA
        iter = 0
        fx = self.f(x)

        while iter < maxIter and temperature > 0.001:

            self.ys.append(fx)
            neighbors = self.getNeighbors(x, reduce = True)
            while len(neighbors) == 0: neighbors = self.getNeighbors(x, reduce = True)
            newx = random.choice(neighbors)
            fNewX = self.f(newx)

            if debug: print("iter: ", iter, temperature, fx, np.exp((fx-fNewX)/temperature))   
            
            if(fNewX < fx):
                x = newx
                fx = fNewX
            elif temperature > 0 and np.random.uniform() < np.exp((fx-fNewX)/temperature):
                x = newx
                fx = fNewX
               
            temperature *= 0.99
            iter += 1

        print("SA ended")
        return x
    
    def updateTabu(self, tabu):
        if len(tabu) > self.tabuMaxSize: tabu.popleft()
        return tabu  
    
    def optimize(self, sa = False, state = None, debug = False):
        # Funcion del Recocido 1
        if state is None: state = self.getInitialSolution(debug = debug)
        # Inicializar tabla tabu en 0
        self.tabuMaxSize = 0
        # Funcion del Recocido 2
        if sa: state = self.preSA(state, debug=debug)
        
        tabu = deque()
        tabu.append(str(state))
        fState = self.f(state)

        bestState = state
        fBestState = fState
        iter = 0
        
        while iter < self.maxiter:
            # Calcular la vecindad
            self.ys.append(fState)
            neighbors = self.getNeighbors(state)
            
            # Sacar mejor estado de la vecindad
            best = 0
            fBest = self.f(neighbors[best])
            
            for i in range(len(neighbors)):
                # Eliminar elementos que existan en la lista tabu
                if str(neighbors[i]) in tabu:
                    continue
                
                fNeighbor = self.f(neighbors[i])
                if fNeighbor < fBest:
                    best = i
                    fBest = fNeighbor
            
            # Actualizar estado
            if(len(neighbors) > 0): 
                state = neighbors[best]
                fState = fBest
            else: print("No new state")
            # Guardar mejor estado
            if fState < fBestState: 
                bestState = state.copy()
                fBestState = fState
            
            # Actualizar tabu     
            iter += 1
            # Tabla dinamica para tabu
            # Aumenta tamaño de la tabla tabu en potencias de 2(consume menos memoria)
            # Incremento logaritmico log2
            # Simula el recocido (mientras mas memoria trae mejores soluciones resultados)
            if ((iter) & (iter-1)) == 0: self.tabuMaxSize+=self.tabuIncrement
            tabu.append(str(state))
            tabu = self.updateTabu(tabu)
            
        return bestState
    
    def stateInfo(self, state):
        print(state)
        print(self.f(state))

        sums = [0 for i in range(self.M)]

        for i, ws in enumerate(state):
            sums[ws] += self.Capacity[i]
            
        print(sums)


# %%
class Graph1D:
    
    def __init__(self, xLim, yLim, title=None, colors=['red']):
        assert(len(xLim) == 2)
        assert(len(yLim) == 2)
        self.colors = colors
        self._range = 500
        self._fig, self._ax = mpl.subplots()
        if title: self._ax.set_title(title, fontsize=20)
        self._fig.set_size_inches(10,7)
        self._ax.set_xlim(xLim)
        self._ax.set_ylim(yLim)
        return
        
    def setLegends(self):
        self._ax.legend()
        
    def legendsDown(self):
        self._ax.legend(loc='upper center', bbox_to_anchor=(0.5, -0.05),
          fancybox=True, shadow=True, ncol=6)
    
    def add_point(self, point, color='r', text=None, dt=0.0, label=None):
        x1, x2 = point
        if label != None: self._ax.scatter(x1,x2,c=color,label=label,alpha=1.0)
        else:             self._ax.scatter(x1,x2,c=color,alpha=0.75)   
        if text:
            self._ax.text(x1,x2+dt,str(text))
            
    def add_line(self, point1, point2, color='black', text=None, dt=0.0):
        x1, y1 = point1
        x2, y2 = point2
        self._ax.plot((x1,x2),(y1,y2), color=color, marker='o')
        if text != None:
            self._ax.text(x1,x2+dt,str(text))
    
    def getfig(self):
        return self._fig, self._ax
    
    def save(self, filename, transparent = False):
        self._fig.savefig(filename, transparent=transparent,  bbox_inches = 'tight')

    def clear(self):
        self._fig.clf()

# %%
class Analyzer: 

    def __init__(self):
        self.arr = []
        self.idx = []
        self.WorkStationPos = []
        self.TerminalPos = []
        self.ys = []

    def add(self, tup, idx, w, t, y):
        self.arr.append(tup)
        self.idx.append(idx)
        self.WorkStationPos.append(w)
        self.TerminalPos.append(t)
        self.ys.append(y)

    def analisis(self,arr = None):

        if arr == None: arr = self.arr.copy()

        Z = 0
        for p,z in arr: Z += z
        
        prom = Z/len(arr)
        
        ZD = 0
        indmin = 0
        indmax = 0
        
        for ind,(p,z) in enumerate(arr):
            #print(f"f{p} = {z}")
            ZD += (z - prom)**2
            if z > arr[indmax][1]: indmax = ind
            if z < arr[indmin][1]: indmin = ind 
                
        print(f'Numero de datos: {len(arr)}')
        print(f"Desviacion estandar: {np.sqrt(ZD/30)}")
        print(f'Promedio: {prom}')
        print(f"Punto maximo f(x) = {arr[indmax][1]}")
        print(f"Punto minimo f(x) = {arr[indmin][1]}")
        print(f"Indice de mejor resultado = {indmax}")
        return arr[indmax], indmax

    def toFile(self, fileName):
        data = {}
        s = 'Ejecucion'
        data[s] = []
        for idx, (best, fBest), w, t, y in zip( self.idx, self.arr, self.WorkStationPos, self.TerminalPos, self.ys):
            data[s].append({
                'Info': idx,
                'Solucion': best,
                'Valor optimo': fBest,
                'WorkStationPos': w,
                'TerminalPos': t,
                'ys': y
            })
        
        with open(fileName, 'w') as outfile:
            json.dump(data, outfile)


# %%
# Colores Grafica
color_names = {name for name in mcd.CSS4_COLORS
           if "xkcd:" + name in mcd.XKCD_COLORS}
colors = [ color for color in color_names]
shuffle(colors)

numColors = 32
limX = (-5,105)
limY = (-5,105)
colors = colors[:numColors]

# %%
analizador = [ Analyzer() for _ in range(7) ]

# %%
ini, fin = 2, 6  # 1, 5

for i in range(ini, fin+1):

    iteraciones = 30 # 10

    for it in range(iteraciones):

        tabu_it, preSA_it = 200, 500
        
        # Tabu, preSA
        o = Optimizator(tabu_it, preSA_it)
        # Para correr todos los casos
        o.readinput(f"inputs/{i}") 
        # o.printDataSum()

        best = o.optimize(debug = False, sa = True)
        print(f'Iteracion {it} - Mejor solucion : {o.f(best)}')
        
        # Añadir al analizador
        analizador[i].add((best, o.f(best)), 
            f'Input {i} Iteracion {it} tabu_it {tabu_it} preSA_it {preSA_it}', 
            o.WorkStationPos, o.TerminalPos, o.ys
        )

        # o.graph(save = True, filename=f"optimization_graph_{i}_it_{it}.png")
        o.graph(save = True, filename=f"outputs/optimization_graph_{i}_it_{it}_tabu_{tabu_it}_preSA_{preSA_it}.png")
        o.clear()

        grafica = Graph1D(limX, limY, title="Distribucion", colors=colors)
        for ind, p in enumerate(o.WorkStationPos):
            grafica.add_point(p, colors[ind], label="Conjunto "+str(ind+1))
        for ind, p in enumerate(o.TerminalPos):       
            grafica.add_point(p, colors[best[ind]])
            grafica.add_line(p, o.WorkStationPos[best[ind]], color=colors[best[ind]])
        grafica.setLegends()
        grafica.legendsDown()
        # grafica.save(f'solution_{i}_it_{it}.png')
        grafica.save(f'outputs/solution_{i}_{i}_it_{it}_tabu_{tabu_it}_preSA_{preSA_it}.png')
        grafica.clear()

# %%
for i in range(ini, fin+1):
    analizador[i].toFile(f'data_{i}.json')
    analizador[i].analisis()
print("Fin analisis")


