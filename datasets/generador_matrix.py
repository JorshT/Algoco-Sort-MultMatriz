import numpy as np
import random

n_small = 100

n_medium = 1000

n_large = 5000

#Para no generar numeros extremadamente gigantes, las matrices tendrán numeros del 0 al 50


matrix_smallA = np.random.randint(0,50,size=(n_small,n_small))
matrix_smallB = np.random.randint(0,50,size=(n_small,n_small))

matrix_mediumA =np.random.randint(0,50,size=(n_medium,n_medium))
matrix_mediumB =np.random.randint(0,50,size=(n_medium,n_medium))

matrix_largeA =np.random.randint(0,50,size=(n_large,n_large))
matrix_largeB =np.random.randint(0,50,size=(n_large,n_large))

with open("matrix_smallA.txt","w") as archivo:
    archivo.write(str(n_small))
    archivo.write("\n")
    for fila in matrix_smallA:
        for elem in fila: 
            archivo.write(str(elem))
            archivo.write(" ")
        archivo.write("\n")

with open("matrix_smallB.txt","w") as archivo:
    archivo.write(str(n_small))
    archivo.write("\n")
    for fila in matrix_smallB:
        for elem in fila: 
            archivo.write(str(elem))
            archivo.write(" ")
        archivo.write("\n")

with open("matrix_mediumA.txt","w") as archivo:
    archivo.write(str(n_medium))
    archivo.write("\n")
    for fila in matrix_mediumA:
        for elem in fila: 
            archivo.write(str(elem))
            archivo.write(" ")
        archivo.write("\n")

with open("matrix_mediumB.txt","w") as archivo:
    archivo.write(str(n_medium))
    archivo.write("\n")
    for fila in matrix_mediumB:
        for elem in fila: 
            archivo.write(str(elem))
            archivo.write(" ")
        archivo.write("\n")


with open("matrix_largeA.txt","w") as archivo:
    archivo.write(str(n_large))
    archivo.write("\n")
    for fila in matrix_largeA:
        for elem in fila: 
            archivo.write(str(elem))
            archivo.write(" ")
        archivo.write("\n")

with open("matrix_largeB.txt","w") as archivo:
    archivo.write(str(n_large))
    archivo.write("\n")
    for fila in matrix_largeB:
        for elem in fila: 
            archivo.write(str(elem))
            archivo.write(" ")
        archivo.write("\n")
