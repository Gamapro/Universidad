print("CONTAINS 5?")

num = int(input("Dame un numero para checar si contiene el 5: "))
si = False

while num > 1:
	digit = num%10
	if digit == 5:
		si = True
	num//=10

print(("SI" if si else "NO")+" contiene el numero 5.")
