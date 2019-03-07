#Generar una cadena con token de 3 letras mayusculas y buscar el token IPN y el numero de veces que aparece
import random
import string
import sys

def createToken(tamanio):
    token = ""
    for i in range(tamanio):
        token += random.choice(string.ascii_letters.upper())
    return token

def searchIPN(tamanio):
    ipn = 0
    for i in range(tamanio):
        ipn = ipn + 1 if createToken(3) == "IPN" else ipn
    return ipn

print("El numero de IPN encontrados fueron %d" % searchIPN(int(sys.argv[1])))