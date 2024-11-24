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
ParPuntos = 'ParPuntos.txt'
Karatsuba = 'Karatsuba.txt'
Books = 'Books.txt'
#mejorCaso = 'mejorCaso.txt'

# Leer los datos de los archivos
x_pp, y_pp = leer_datos(ParPuntos)
x_Karatsuba, y_Karatsuba = leer_datos(Karatsuba)
x_Books, y_Books = leer_datos(Books)
#x_mejor, y_mejor = leer_datos(mejorCaso)

# Graficar los datos con marcadores más visibles
plt.plot(x_pp, y_pp, label='Par puntos mas cercanos', marker='*', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_Karatsuba, y_Karatsuba, label='Karatsuba', marker='^', markersize=8, linestyle='-', linewidth=2)
plt.plot(x_Books,y_Books, label='Libros Minimizados', marker='s', markersize=8, linestyle='-', linewidth=2)
#plt.plot(x_mejor, y_mejor, label='Mejor Caso', marker='^', markersize=8, linestyle='-', linewidth=2)

# Personalización de la gráfica
plt.title('Divide y Venceras')
plt.xlabel('Cantidad de elementos [n]')
plt.ylabel('Tiempo [s]')
plt.legend()  # Mostrar leyendas
plt.grid(True)  # Mostrar la cuadrícula
# plt.xscale('log')  # Escala logarítmica en el eje X si fuera necesario
plt.show()
#guardar_grafica("C:\Users\52553\Documents\ESCOM\Tercer_Semestre\ADA\ESCOM_analysis-and-design-of-algorithms\SegundoParcial\Practica7\Graficas", "sum-max-sub")
