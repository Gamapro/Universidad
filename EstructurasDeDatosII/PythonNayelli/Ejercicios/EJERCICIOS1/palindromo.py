print("PALINDROMO")
s = input("Dame una cadena para checar si es o no palindromo: ")

# Preprocesar
#print("Antes",s)
s = s.lower()
s = s.replace(' ','')
#print("Despues",s)

n = len(s)
si = True
for i in range(n//2):
	if s[i] != s[n-i-1]:
		si = False
		break
print("La cadena "+("SI" if si else "NO")+" es palindromo.")

