arr = []
for i in range(10):
    arr[i] = input("escribe un numero: ")
    
for i in range(10):
    print(arr[i], end=" ")
print()
for i in range(9, -1, -1):
    print(arr[i], end=" ")
print()