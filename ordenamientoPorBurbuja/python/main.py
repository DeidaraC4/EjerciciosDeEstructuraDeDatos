arr = [64, 39, 82, 37, 49, 21, 18, 54, 21, 34, 87, 21, 32, 41, 23, 23, 67, 98, 43, 56]
bubble = 0

print("los elementos del array desordenado son:")
for ele in arr:
    print(ele, end=" ")
print()

for i in range(19):
    for j in range(19 - i):
        if arr[j] > arr[j+1]:
            bubble = arr[j+1]
            arr[j+1] = arr[j]
            arr[j] = bubble

print("\nlos elementos del array ordenado son:")
for ele in arr:
    print(ele, end=" ")
print()