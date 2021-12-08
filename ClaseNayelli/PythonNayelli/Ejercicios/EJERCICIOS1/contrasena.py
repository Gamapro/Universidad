print("CONTRASEÑA VALIDA")

s = input("Ingrese la contraseña para checar si es valida o no: ")
print("Su contraseña es: "+s)
mayus, minus, special= False, False, False

if len(s) < 8:
	print("Su contraseña no es valida, debe tener al menos 8 caracteres")
else:
	for c in s:
		if (c >= 'a' and c <= 'z') or c == 'ñ':
			minus = True
		elif  (c >= 'A' and c <= 'Z') or c == 'Ñ': 
			mayus = True
		elif not(c >= '0' and c <= '9'):
			special = True
	if mayus and minus and special:
		print("Su contraseña {} es valida.".format(s))
	else:
		print("""Su contraseña no es valida, debe tener al menos\nuna minuscula, una mayuscula y un caracter especial""")

print("Tamaño:",len(s))
print("Mayus:",mayus)
print("Minus:",minus)
print("Caracter Especial:",special)

