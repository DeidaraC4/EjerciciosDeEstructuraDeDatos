colores = ["rojo", "verde", "amarillo", "azul"]

print(colores)

for color in colores:
    print(color)

colores[2] = 5

print(colores)

colores.append("azul")

print(colores)

colores[:] = "deletrar"
print(colores)

del colores

try:
    print(colores)
except:
    print("el array fue eliminado")