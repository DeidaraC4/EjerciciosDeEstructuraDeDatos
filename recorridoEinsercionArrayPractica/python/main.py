arr = [10, 20, 30, 40, 50, 60]

print("Los elementos del array son: \n")
for itm in arr:
    print(itm, end=" ")
print()

print("escribe un numero: ")
num = int(input())
print("en que posicion quieres que se guarde? (0-5)")
position = int(input())

arr.insert(position, num)
print("\nEl array modificado es: ")
arr.pop()


for itm in arr:
    print(itm, end=" ")
print()