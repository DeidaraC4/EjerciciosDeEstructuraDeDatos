import math;
arr = [0.93, 0.4, 0.50, 0.34, 0.94, 0.90, 0.94, 0.992, 0.42, 0.34, 0.42, 0.33, 0.25, 0.2, 0.04, 0.19, 0.52, 0.07, 0.32]

bucket = [[] for i in range(10)]

print("Elementos desordenados: ")
for ele in arr:
    print(ele, end=" ")
print()

for ele in arr:
    bucket[math.floor(ele*10)].append(ele)

arr.clear()

for list in bucket:
    for i in range(1, len(list)):
        temp = list[i]

        j = i - 1
        while j >= 0 and temp < list[j]:
            list[j + 1] = list[j]
            j -= 1
        list[j + 1] = temp
    arr.extend(list)
    

print("Elementos ordenados: ")
for ele in arr:
    print(ele, end=" ")
print()