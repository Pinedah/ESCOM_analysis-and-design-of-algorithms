import matplotlib.pyplot as plt

def leer_puntos_desde_archivo(archivo):
    puntos_x = []
    puntos_y = []
    with open(archivo, 'r') as file:
        for line in file:
            x, y = map(float, line.strip().split(','))
            puntos_x.append(x)
            puntos_y.append(y)
    return puntos_x, puntos_y

def graficar_curva(valores_x, valores_y):
    plt.plot(valores_x, valores_y)
    plt.xlabel('Eje X')
    plt.ylabel('Eje Y')
    plt.title('Gráfico de una Curva')
    plt.grid(True)
    plt.show()

# Nombre del archivo
archivo = 'points.txt'

# Leer los puntos desde el archivo
valores_x, valores_y = leer_puntos_desde_archivo(archivo)

# Graficar los puntos
graficar_curva(valores_x, valores_y)
