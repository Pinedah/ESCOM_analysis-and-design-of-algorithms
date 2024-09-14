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
archivo1 = 'peorCaso.txt'
archivo2 = 'casoPromedio.txt'
archivo3 = 'mejorCaso.txt'

# Leer los datos de los archivos
x1, y1 = leer_datos(archivo1)
x2, y2 = leer_datos(archivo2)
x3, y3 = leer_datos(archivo3)

# Graficar los datos
plt.plot(x1, y1, label='Peor Caso', marker='o')
plt.plot(x2, y2, label='Caso Promedio', marker='s')
plt.plot(x3, y3, label='Mejor Caso', marker='^')

# Personalización de la gráfica
plt.title('Nombre de los algoritmos...')
plt.xlabel('Número de Iteraciones [n]')
plt.ylabel('Tiempo [s]')
plt.legend()  # Mostrar leyendas
plt.grid(True)  # Mostrar la cuadrícula
plt.xscale('log')  # Escala logarítmica en el eje X si fuera necesario
plt.show()
