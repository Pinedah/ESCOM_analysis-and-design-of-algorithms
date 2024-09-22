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

# Función para guardar la gráfica
def guardar_grafica(ruta_guardado, nombre_archivo):
    # Crear la ruta completa incluyendo el nombre del archivo
    ruta_completa = f"{ruta_guardado}/{nombre_archivo}.png"
    plt.savefig(ruta_completa, format='png', dpi=300)
    print(f"Gráfica guardada en: {ruta_completa}")

# Archivos txt con los datos
merge = 'merge.txt' # quick
#casoPromedio = 'casoPromedio.txt'
quick = 'quick.txt' # merge

# Leer los datos de los archivos
x_peor, y_peor = leer_datos(merge)
#x_promedio, y_promedio = leer_datos(casoPromedio)
x_mejor, y_mejor = leer_datos(quick)

# Graficar los datos con marcadores más visibles
plt.plot(x_peor, y_peor, label='Merge Sort', marker='o', markersize=8, linestyle='-', linewidth=2)
#plt.plot(x_promedio, y_promedio, label='Caso Promedio', marker='s', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_mejor, y_mejor, label='quick Sort', marker='^', markersize=8, linestyle='-', linewidth=2)

# Personalización de la gráfica
plt.title('ALGORITMOS RECURSIVOS (PEOR CASO)')
plt.xlabel('Cantidad de elementos [n]')
plt.ylabel('Tiempo [s]')
plt.legend()  # Mostrar leyendas
plt.grid(True)  # Mostrar la cuadrícula
# plt.xscale('log')  # Escala logarítmica en el eje X si fuera necesario
#plt.show()

guardar_grafica('graficas', "quick-merge-peor")