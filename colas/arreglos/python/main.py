MAXSIZE = 5
queue = [0] * MAXSIZE
front = -1
rear = -1

def insertar():
    global front, rear, queue
    
    try:
        elemento = int(input("\nIngrese el elemento: "))
    except ValueError:
        print("\nEntrada no válida.\n")
        return

    if rear == MAXSIZE - 1:
        print("\nDESBORDAMIENTO (OVERFLOW)\n")
        return
    
    if front == -1 and rear == -1:
        front = rear = 0
    else:
        rear += 1
    
    queue[rear] = elemento
    print("\nElemento insertado correctamente.\n")

def eliminar():
    global front, rear, queue
    
    if front == -1 or front > rear:
        print("\nSUBDESBORDAMIENTO (UNDERFLOW)\n")
        return
    
    elemento = queue[front]
    
    if front == rear:
        front = rear = -1
    else:
        front += 1
        
    print(f"\nElemento eliminado: {elemento}\n")

def mostrar():
    global front, rear, queue
    
    if rear == -1 or front == -1 or front > rear:
        print("\nLa cola esta vacia.\n")
    else:
        print("\nElementos en la cola:\n")
        for i in range(front, rear + 1):
            print(queue[i])

def main():
    opcion = 0
    while opcion != 4:
        print("\n************************* MENU PRINCIPAL ***************************\n")
        print("======================================================================\n")
        print("1. Insertar un elemento\n")
        print("2. Eliminar un elemento\n")
        print("3. Mostrar La cola\n")
        print("4. Salir\n")
        
        try:
            opcion = int(input("Ingrese su opcion: "))
        except ValueError:
            opcion = -1

        if opcion == 1:
            insertar()
        elif opcion == 2:
            eliminar()
        elif opcion == 3:
            mostrar()
        elif opcion == 4:
            print("\nSaliendo del programa...\n")
        else:
            print("\nOpcion invalida. Intente nuevamente.\n")

# Esto simula la ejecución de main() en C++
if __name__ == "__main__":
    main()