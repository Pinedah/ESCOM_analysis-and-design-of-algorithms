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
archivo1 = 'points.txt'
#archivo2 = 'datos2.txt'
#archivo3 = 'datos3.txt'

# Leer los datos de los archivos
x1, y1 = leer_datos(archivo1)
#x2, y2 = leer_datos(archivo2)
#x3, y3 = leer_datos(archivo3)

# Graficar los datos
plt.plot(x1, y1, label='Datos 1', marker='o')
#plt.plot(x2, y2, label='Datos 2', marker='s')
#plt.plot(x3, y3, label='Datos 3', marker='^')

# Personalización de la gráfica
plt.title('Comparación de Gráficas')
plt.xlabel('Eje X')
plt.ylabel('Eje Y')
plt.legend()  # Mostrar leyendas
plt.grid(True)  # Mostrar la cuadrícula
plt.xscale('log')  # Escala logarítmica en el eje X si fuera necesario
plt.show()
