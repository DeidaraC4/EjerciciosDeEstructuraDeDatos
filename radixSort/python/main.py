arr = [938, 4, 102, 30, 5, 2, 4928, 701, 230, 71, 92, 474, 91, 2]

print("desordenados: ")
for ele in arr:
    print(ele, end=" ")
print()

max = arr[0]
for ele in arr:
    if max < ele:
        max = ele

cont = 1
while 1 < max:
    max /= 10
    cont += 1

for k in range(cont):
    for i in range(1, len(arr)):
        reserva = arr[i]

        j = i-1
        while j >= 0 and int(reserva / (10 ** k)) % 10 < int(arr[j] / (10 ** k)) % 10:
            arr[j + 1] = arr[j]

            j -= 1
        arr[j + 1] = reserva

print("ordenados: ")
for ele in arr:
    print(ele, end=" ")
print()