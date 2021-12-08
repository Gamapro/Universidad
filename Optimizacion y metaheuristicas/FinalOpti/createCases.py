import numpy as np
def solToFile(idx='best'):
    f = open(f"inputs/{idx}", 'w')
    
    n = 100
    f.write(f'{n}\n')    
    capacity = np.random.randint(1, 6 + 1, size=(n))
    x = np.random.randint(1, 100 + 1, size=(n))
    y = np.random.randint(1, 100 + 1, size=(n))
    for i in range(n):
        f.write(f'{capacity[i]} {x[i]} {y[i]}\n')
    
    m = 32
    f.write(f'{m}\n')    
    demand = np.random.randint(10, 15 + 1, size=(m))
    x_ = np.random.randint(1, 100 + 1, size=(m))
    y_ = np.random.randint(1, 100 + 1, size=(m))
    for i in range(m):
        f.write(f'{demand[i]} {x[i]} {y[i]}\n')
    
    f.close()
    return

for i in range(3,4):
    solToFile(idx=i)