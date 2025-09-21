arr = [45, 62, 41, 41, 34, 31, 87, 99, 86, 15]
def printArr(arr):
    for ele in arr:
        print(ele, end=" ")
    print()

print("El array desordenado es: ")
printArr(arr)

for i in range(len(arr)):
    little = i
    for j in range(i + 1, len(arr)):
        if arr[little] > arr[j]:
            little = j
    arr[i], arr[little] = arr[little], arr[i]

print("El array ordenado es: ")
printArr(arr)