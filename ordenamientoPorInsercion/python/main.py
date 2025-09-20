arr = [29, 84, 56, 2, 76, 37, 39, 2]

def printArr(arr):
    for ele in arr:
        print(ele, end=" ")
    print()

print("El array desordenado es: ")
printArr(arr)

for i in range(1, len(arr)):
    reserva = arr[i]

    j = i-1
    while i >= 0 and reserva < arr[j]:
        arr[j + 1] = arr[j]

        j -= 1
    arr[j + 1] = reserva

print("El array ordenado es: ")
printArr(arr)