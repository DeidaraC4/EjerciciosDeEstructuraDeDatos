#%%
import numpy as np
import time
import math
import matplotlib.pyplot as plt
import random

def selecDatos(opt: int):
    match opt:
        case 1:
            return np.random.randint(1, 1000, 100)
        case 2:
            return np.random.randint(1, 1000, 1000)
        case 3:
            return np.random.randint(1, 1000, 10000)
        case 4:
            return np.random.randint(1, 1000, 100000)
    
def semiOrdenar(arr):
    div = (len(arr) - 1)//2

    while div >= 5:
        separation = div
        for i in range(div, len(arr)):
            reserve = arr[i]

            j = i-separation
            while j >= 0 and reserve < arr[j]:
                arr[j + separation] = arr[j]

                j -= separation
            arr[j + separation] = reserve
        div //= 2

def hashSort(arr):
    startTime = time.time()
    div = (len(arr) - 1)//2

    while div >= 1:
        separation = div
        for i in range(div, len(arr)):
            reserve = arr[i]

            j = i-separation
            while j >= 0 and reserve < arr[j]:
                arr[j + separation] = arr[j]

                j -= separation
            arr[j + separation] = reserve
        div //= 2
    endTime = time.time()
    return ["Hash Sort", endTime - startTime]

def merge(array, left, mid, right):
    a1 = mid - left + 1
    a2 = right - mid

    L = [0] * a1
    R = [0] * a2

    for j in range(a1):
        L[j] = array[left + j]
    
    for k in range(a2):
        R[k] = array[mid + 1 + k]
    i = 0
    j = 0
    k = left

    while i < a1 and j < a2:
        if L[i] < R[j]:
            array[k] = L[i]
            i += 1
            k += 1
        else:
            array[k] = R[j]
            j += 1
            k += 1
    
    while i < a1:
        array[k] = L[i]
        i += 1
        k += 1
    
    while j < a2:
        array[k] = R[j]
        j += 1
        k += 1

def mSort(array, left, right):
    if left < right:

        mid = (right - left)//2 + left

        mSort(array, left, mid)
        mSort(array, mid + 1, right)
        merge(array, left, mid, right)

def mergeSort(array, left, right):
    startTime = time.time()
    mSort(array, left, right)
    endTime = time.time()
    return ["Merge Sort", endTime - startTime]

def heapSort(array): #modificado
    startTime = time.time()

    def heapify(arr, n, i):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2

        if left < n and arr[left] > arr[largest]:
            largest = left

        if right < n and arr[right] > arr[largest]:
            largest = right

        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            heapify(arr, n, largest)

    n = len(array)

    for i in range(n // 2 - 1, -1, -1):
        heapify(array, n, i)

    for i in range(n - 1, 0, -1):
        array[i], array[0] = array[0], array[i]
        heapify(array, i, 0)
        
    endTime = time.time()
    return ["Heap Sort", endTime - startTime]


def bubbleSort(arr):
    startTime = time.time()
    bubble = 0
    for i in range(len(arr) - 1):
        for j in range(len(arr) - 1 - i):
            if arr[j] > arr[j+1]:
                bubble = arr[j+1]
                arr[j+1] = arr[j]
                arr[j] = bubble
    endTime = time.time()
    return ["Bubble Sort", endTime - startTime]

def insertionSort(arr):
    startTime = time.time()
    for i in range(1, len(arr)):
        reserva = arr[i]

        j = i-1
        while j >= 0 and reserva < arr[j]:
            arr[j + 1] = arr[j]

            j -= 1
        arr[j + 1] = reserva
    endTime = time.time()
    return ["Insertion Sort", endTime - startTime]

def selectionSort(arr):
    startTime = time.time()
    for i in range(len(arr)):
        little = i
        for j in range(i + 1, len(arr)):
            if arr[little] > arr[j]:
                little = j
        arr[i], arr[little] = arr[little], arr[i]
    endTime = time.time()
    return ["Selection Sort", endTime - startTime]


def getPivot(array, start, end):
    pivot_index = random.randint(start, end)
    array[end], array[pivot_index] = array[pivot_index], array[end]
    
    i = start - 1

    for j in range(start, end):
        if array[j] <= array[end]:
            i += 1
            array[i], array[j] = array[j], array[i]
            
    array[i + 1], array[end] = array[end], array[i + 1]
    
    return i + 1

def qSort(array, start, end):
    while start < end:
        pivot = getPivot(array, start, end)
        
        if pivot - start < end - pivot:
            qSort(array, start, pivot - 1)
            start = pivot + 1
        else:
            qSort(array, pivot + 1, end)
            end = pivot - 1

def quickSort(array, start, end):
    startTime = time.time()
    qSort(array, start, end)
    endTime = time.time()
    return ["Quick Sort", endTime - startTime]

def countingSortForRadix(arr, exp): #parte de radix modificado
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]

def radixSort(arr):
    startTime = time.time()
        
    max_val = max(arr)
    
    exp = 1
    while max_val // exp > 0:
        countingSortForRadix(arr, exp)
        exp *= 10
        
    endTime = time.time()
    return ["Radix Sort", endTime - startTime]


def bucketSort(arr): #bucketSort corregido(solo para 1000 elementos)
    startTime = time.time()
    
    if not arr:
        endTime = time.time()
        return ["Bucket Sort", endTime - startTime]

    max_val = max(arr)
    num_buckets = 10
    
    bucket_size = math.ceil((max_val + 1) / num_buckets)
    
    if bucket_size == 0:
        bucket_size = 1

    buckets = [[] for _ in range(num_buckets)]

    for ele in arr:
        index = int(ele / bucket_size)
        if index == num_buckets:
            index -= 1
        buckets[index].append(ele)

    arr.clear()
    for bucket in buckets:
        for i in range(1, len(bucket)):
            temp = bucket[i]
            j = i - 1
            while j >= 0 and temp < bucket[j]:
                bucket[j + 1] = bucket[j]
                j -= 1
            bucket[j + 1] = temp
        
        arr.extend(bucket)

    endTime = time.time()
    return ["Bucket Sort", endTime - startTime]


def whoIsEfficient(arr: list, opt):
    vel = []
    if opt < 4:
        vel.append(hashSort(arr.copy()))
        vel.append(mergeSort(arr.copy(), 0, len(arr) - 1))
        vel.append(heapSort(arr.copy()))
        vel.append(bubbleSort(arr.copy()))
        vel.append(insertionSort(arr.copy()))
        vel.append(selectionSort(arr.copy()))
        vel.append(quickSort(arr.copy(), 0, len(arr) - 1))
        vel.append(radixSort(arr.copy()))
    else:
        vel.append(hashSort(arr.copy()))
        vel.append(mergeSort(arr.copy(), 0, len(arr) - 1))
        vel.append(quickSort(arr.copy(), 0, len(arr) - 1))
        
    vel.sort(key = lambda ele: ele[1])
    return vel

def graph(arr, titulo):
    algoName = []
    timeSpent = []
    for i in range(len(arr)):
        algoName.append(arr[i][0])
        timeSpent.append(arr[i][1])

    xPos = np.arange(len(arr))
    plt.bar(xPos, timeSpent, color="skyblue")
    plt.xticks(xPos, algoName, rotation=45)
    plt.title(titulo)
    plt.xlabel("algoritmo")
    plt.ylabel("tiempo")

    plt.tight_layout()
    plt.show()

opt = False

print("============================================")
print("   analisis de algoritmos de ordenamiento   ")
print("============================================", end="\n")
print("Elegir uno de los siguientes arreglos para realizar las pruebas:")
print("     1: 100 datos")
print("     2: 1 000 datos")
print("     3: 10 000 datos")
print("     4: 100 000 datos")
while type(opt) != int or opt > 4 or opt < 1:
    try:
        opt = int(input(">> "))
        arr = selecDatos(opt)
        semiOrdenar(arr)
    except:
        opt = False

efficientList = whoIsEfficient(arr, opt)
graph(efficientList, "caso semi ordenado")

arr.sort()
efficientList = whoIsEfficient(arr, opt)
graph(efficientList, "caso ordenado")

arr.sort()
arr = arr[::-1]
efficientList = whoIsEfficient(arr, opt)
graph(efficientList, "caso ordenado inverso")

# %%
