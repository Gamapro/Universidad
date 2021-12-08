
cant, v = 0, [0,0,0,0,0,0,0]

def cambio(cant,v):
    v[0]+=cant//100
    cant%=100
    v[1]+=cant//50
    cant%=50
    v[2]+=cant//20
    cant%=20
    v[3]+=cant//10
    cant%=10
    v[4]+=cant//5 
    cant%=5
    v[5]+=cant//2
    cant%=2
    v[6]+=cant
    cant+=1
    return

cant = int(input("Ingrese una cantidad: "))
cambio(cant,v)

print("Cantidad en billetes/monedas.")
print("100$: "+str(v[0]))
print("50$: "+str(v[1]))
print("20$: "+str(v[2]))
print("10$: "+str(v[3]))
print("5$: "+str(v[4]))
print("2$: "+str(v[5]))
print("1$: "+str(v[6]))


