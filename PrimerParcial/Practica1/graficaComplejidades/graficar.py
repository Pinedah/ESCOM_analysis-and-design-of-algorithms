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

def guardar_grafica(ruta_guardado, nombre_archivo):
    # Crear la ruta completa incluyendo el nombre del archivo
    ruta_completa = f"{ruta_guardado}/{nombre_archivo}.png"
    plt.savefig(ruta_completa, format='png', dpi=300)
    print(f"Gráfica guardada en: {ruta_completa}")
# Archivos txt con los datos
Kadanne = 'Kadanne.txt'
DivideYVenceras = 'DivideYVenceras.txt'
#mejorCaso = 'mejorCaso.txt'

# Leer los datos de los archivos
x_iter, y_iter = leer_datos(Kadanne)
x_recur, y_recur = leer_datos(DivideYVenceras)
#x_mejor, y_mejor = leer_datos(mejorCaso)

# Graficar los datos con marcadores más visibles
plt.plot(x_iter, y_iter, label='Sum Max Kadanne', marker='o', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_recur, y_recur, label='Sum Max Divide y Venceras', marker='^', markersize=8, linestyle='-', linewidth=2)
#plt.plot(x_mejor, y_mejor, label='Mejor Caso', marker='^', markersize=8, linestyle='-', linewidth=2)

# Personalización de la gráfica
plt.title('Suma Maxima En subArreglo')
plt.xlabel('Cantidad de elementos [n]')
plt.ylabel('Tiempo [s]')
plt.legend()  # Mostrar leyendas
plt.grid(True)  # Mostrar la cuadrícula
# plt.xscale('log')  # Escala logarítmica en el eje X si fuera necesario
plt.show()
guardar_grafica('graficas', "sum-max-sub")
