import math

def heapSort(array):
    for i in range(1, len(array)):
        for j in range(len(array) - i, 0, -1):
            if array[j] > array[math.floor((j-1)/2)]:
                array[j], array[math.floor((j-1)/2)] = array[math.floor((j-1)/2)], array[j]
        array[len(array) - i], array[0] = array[0], array[len(array) - i]

arr = [6, 1, 5, 60, 13, 2, 78, 41, 11, 14, 18, 38, 484, 23, 1]

print("Los elementos desordenados son: ")
for ele in arr:
    print(ele, end=" ")
print()

heapSort(arr)

print("Los elementos ordenados son: ")
for ele in arr:
    print(ele, end=" ")
print()