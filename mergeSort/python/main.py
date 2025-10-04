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

def mergeSort(array, left, right):
    if left < right:

        mid = (right - left)//2 + left

        mergeSort(array, left, mid)
        mergeSort(array, mid + 1, right)
        merge(array, left, mid, right)


arr = [34, 1, 48, 71, 29, 12, 303, 81, 8, 315, 3, 4, 32, 52, 53]

print("los elementos desordenados son: ")
for i in arr:
    print(i, end=" ")
print()

mergeSort(arr, 0, len(arr) - 1)

print("los elementos ordenados son: ")
for i in arr:
    print(i, end=" ")
print()