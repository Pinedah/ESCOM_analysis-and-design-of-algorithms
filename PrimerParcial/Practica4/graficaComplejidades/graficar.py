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
facIterativo = 'facIterativo.txt'
facRecursivo = 'facRecursivo.txt'
fibIterativo = 'fibIterativo.txt'
fibRecursivo = 'fibRecursivo.txt'
tHIterativo = 'tHIterativo.txt'
tHRecursivo = 'tHRecursivo.txt'
#mejorCaso = 'mejorCaso.txt'

# Leer los datos de los archivos
x_fac_iter, y_fac_iter = leer_datos(facIterativo)
x_fac_recur, y_fac_recur = leer_datos(facRecursivo)
x_fib_iter, y_fib_iter = leer_datos(fibIterativo)
x_fib_recur, y_fib_recur = leer_datos(fibRecursivo)
x_th_iter, y_th_iter = leer_datos(tHIterativo)
x_th_recur, y_th_recur = leer_datos(tHRecursivo)
#x_mejor, y_mejor = leer_datos(mejorCaso)

# Graficar los datos con marcadores más visibles
plt.plot(x_fac_iter, y_fac_iter, label='Factorial Iterativo', marker='o', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_fac_recur, y_fac_recur, label='Factorial Recursivo', marker='^', markersize=8, linestyle='-', linewidth=2)
#plt.plot(x_mejor, y_mejor, label='Mejor Caso', marker='^', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_fib_iter, y_fib_iter, label='Fibonacci Iterativo', marker='p', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_fib_recur, y_fib_recur, label='Fibonacci Recursivo', marker='8', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_th_iter, y_th_iter, label='Torres Hanoi Iterativo', marker='P', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_th_recur, y_th_recur, label='Torres Hanoi Recursivo', marker='*', markersize=8, linestyle='-', linewidth=2)
# Personalización de la gráfica
plt.title('ITERATIVO VS RECURSIVO')
plt.xlabel('Cantidad de elementos [n]')
plt.ylabel('Tiempo [s]')
plt.legend()  # Mostrar leyendas
plt.grid(True)  # Mostrar la cuadrícula
# plt.xscale('log')  # Escala logarítmica en el eje X si fuera necesario
plt.show()
