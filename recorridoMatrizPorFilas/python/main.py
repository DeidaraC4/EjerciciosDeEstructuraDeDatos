arr = [0] * 9
TwoDArr = [[1, 2, 3],
           [4, 5, 6],
           [7, 8, 9],
]
k = 0
print("Los elementos del array bidimensional son: ")
for row in TwoDArr:
    for ele in row:
        print(ele, end=" ")
        arr[k] = ele
        k += 1
    print()

print("\nLos elementos del array unidimensional son: ")

for x in arr:
    print(x, end=" ")