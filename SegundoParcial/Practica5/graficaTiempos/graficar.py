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
iterativa = 'iterativa.txt' # recursiva
recursiva = 'recursiva.txt' # iterativa

# Leer los datos de los archivos
x_iterativa, y_iterativa = leer_datos(iterativa)
x_recursiva, y_recursiva = leer_datos(recursiva)

# Graficar los datos con marcadores más visibles
plt.plot(x_iterativa, y_iterativa, label='Forma Iterativa', marker='o', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_recursiva, y_recursiva, label='Forma Recursiva', marker='^', markersize=8, linestyle='-', linewidth=2)

# Personalización de la gráfica
plt.title('BUSCAR ELEMENTOS MÁXIMO Y MÍNIMO')
plt.xlabel('Cantidad de elementos [n]')
plt.ylabel('Tiempo [s]')
plt.legend()  # Mostrar leyendas
plt.grid(True)  # Mostrar la cuadrícula
# plt.xscale('log')  # Escala logarítmica en el eje X si fuera necesario
# vplt.show()

guardar_grafica('graficas', "busqueda-max-min")