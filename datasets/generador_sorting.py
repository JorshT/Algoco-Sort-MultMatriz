import numpy as np
import random


size_small = 10000
size_medium = 1000000
size_large = 10000000
rango = 100000

lista_small = np.random.randint(0,rango,size_small).tolist()

lista_medium = np.random.randint(0,rango,size_medium).tolist()

lista_large = np.random.randint(0,rango,size_large).tolist()

with open("small_lists_to_sort.txt","w") as archivo:
    archivo.write(str(size_small))
    archivo.write("\n")
    for elem in lista_small:
        archivo.write(str(elem))
        archivo.write("\n")

with open("medium_lists_to_sort.txt","w") as archivo:
    archivo.write(str(size_medium))
    archivo.write("\n")
    for elem in lista_medium:
        archivo.write(str(elem))
        archivo.write("\n")

with open("large_lists_to_sort.txt","w") as archivo:
    archivo.write(str(size_large))
    archivo.write("\n")
    for elem in lista_large:
        archivo.write(str(elem))
        archivo.write("\n")