arr = [0] * 9
TwoDArr = [[1, 2, 3],
           [4, 5, 6],
           [7, 8, 9],
]
k = 0
print("Los elementos del array bidimensional son: ")
for i in range(3):
    for j in range(3):
        print(TwoDArr[j][i], end=" ")
        arr[k] = TwoDArr[j][i]
        k += 1
    print()

print("\nLos elementos del array unidimensional son: ")

for x in arr:
    print(x, end=" ")