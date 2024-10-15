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
Iterativo = 'Iterativo.txt'
Recursivo = 'Recursivo.txt'
#mejorCaso = 'mejorCaso.txt'

# Leer los datos de los archivos
x_iter, y_iter = leer_datos(Iterativo)
x_recur, y_recur = leer_datos(Recursivo)
#x_mejor, y_mejor = leer_datos(mejorCaso)

# Graficar los datos con marcadores más visibles
plt.plot(x_iter, y_iter, label='factorial Iterativo', marker='o', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_recur, y_recur, label='factorial Recursivo', marker='s', markersize=8, linestyle='-', linewidth=2)
#plt.plot(x_mejor, y_mejor, label='Mejor Caso', marker='^', markersize=8, linestyle='-', linewidth=2)

# Personalización de la gráfica
plt.title('FACTORIAL')
plt.xlabel('Cantidad de elementos [n]')
plt.ylabel('Tiempo [s]')
plt.legend()  # Mostrar leyendas
plt.grid(True)  # Mostrar la cuadrícula
# plt.xscale('log')  # Escala logarítmica en el eje X si fuera necesario
plt.show()
