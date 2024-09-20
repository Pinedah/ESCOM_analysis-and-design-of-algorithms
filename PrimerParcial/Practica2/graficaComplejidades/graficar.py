import matplotlib.pyplot as plt

# Función para leer datos desde un archivo txt
def leer_datos(archivo):
    x = []
    y = []
    with open(archivo, 'r') as f:
        for linea in f:
            datos = linea.split(',')  # Separar por comas
            x.append(float(datos[0]))
            y.append(float(datos[1]))
    return x, y

# Archivos txt con los datos
merge = 'merge.txt' # quick
# casoPromedio = 'casoPromedio.txt'
quick = 'quick.txt' # merge

# Leer los datos de los archivos
x_peor, y_peor = leer_datos(merge)
# x_promedio, y_promedio = leer_datos(casoPromedio)
x_mejor, y_mejor = leer_datos(quick)

# Graficar los datos con marcadores más visibles
plt.plot(x_peor, y_peor, label='Merge Sort', marker='o', markersize=8, linestyle='-', linewidth=2)
# plt.plot(x_promedio, y_promedio, label='Caso Promedio', marker='s', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_mejor, y_mejor, label='Quick Sort', marker='^', markersize=8, linestyle='-', linewidth=2)

# Personalización de la gráfica
plt.title('ALGORITMOS RECURSIVOS (CASOS MEDIOS)')
plt.xlabel('Cantidad de elementos [n]')
plt.ylabel('Tiempo [s]')
plt.legend()  # Mostrar leyendas
plt.grid(True)  # Mostrar la cuadrícula
#plt.xscale('log')  # Escala logarítmica en el eje X si fuera necesario
plt.show()
