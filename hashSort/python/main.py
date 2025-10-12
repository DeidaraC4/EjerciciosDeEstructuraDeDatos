#en realidad es shellsort
arr = [4, 10, 9, 47, 90, 9, 3, 341, 551, 79, 8]

print("Los elementos desordenados son: ")
for ele in arr:
    print(ele, end=" ")
print()

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

print("Los elementos desordenados son: ")
for ele in arr:
    print(ele, end=" ")
print()