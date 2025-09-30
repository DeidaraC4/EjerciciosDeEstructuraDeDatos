def getPivot(array, start, end):
    temp = 0
    i = start - 1

    for j in range(start, end + 1):
        if array[j] <= array[end]:
            i += 1
            temp = array[i]
            array[i] = array[j]
            array[j] = temp
                
    return i

def quickSort(array, start, end):

    if end <= start: 
        return #salir de la funcion cuando se ordenen las sublistas

    pivot = getPivot(array, start, end)
    quickSort(array, start, pivot - 1)
    quickSort(array, pivot + 1, end)

arr = [78, 64, 91, 73, 40, 15, 91, 36, 47, 51, 67, 19, 34, 69, 2, 1, 36, 4, 49, 7, 25, 94, 53, 5, 2]
#son 25 elementos en el arr

print("los elementos desordenados del arreglo son: ")
for i in arr:
    print(i, end=" ")
print()

quickSort(arr, 0, len(arr) - 1)

print("los elementos ordenados del arreglo son: ")
for i in arr:
    print(i, end=" ")
print()