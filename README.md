# Algoco-Sort-MultMatriz
En este repositorio dejo en evidencia los algoritmos utilizados para ordenar y multiplicar matrices en mi tarea de algoritmos y complejidad.

Para los datasets, que se encuentran en su respectiva carpeta, hay dos generadores, el primero (generador_sorting.py) nos crea tres archivos de texto que guardan tres tipos de instancias, pequeñas, medianas y grandes que son una lista de enteros desordenada generada de forma aleatoria.  
El otro nos genera 6 archivos de texto, 2 correspondientes a cada instancia que guarda la informacion de cada matriz de tamaño n*n.
Ambos generdores fueron creados con python, dando uso a la libreria numpy y random.  

Para los algoritmos, se disponen de dos archivos en lenguaje C + +. Uno de ellos llamado std_sort.cpp contiene todos los algoritmos de sorting utilizados en esta entrega, desde selection_sort hasta quick_sort. Además es el que utilicé para obtener los distintos tiempos de ejecucion para cada instancia.  
El segundo archivo llamado cubico.cpp contiene los tres tipos de algoritmos de multiplicacion de matrices; convencional, transpuesto y el algoritmo de strassen. En este archivo ejecuté y obtuve los distintos tiempos de ejecucion para cada instancia.  
