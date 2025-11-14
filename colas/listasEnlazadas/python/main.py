class Node:
    def __init__(self, dato):
        self.data = dato
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.fin = None

    def LastInsert(self, data):
        ptr = Node(data)

        if self.head is None:
            ptr.next = self.head 
            self.head = ptr
            self.fin = ptr
        else:
            self.fin.next = ptr
            self.fin = ptr

    def begin_delete(self):
        if self.head is None:
            print("la lista esta vacia")
        else:
            data = self.head.data
            self.head = self.head.next
            return data
        return None

    def display(self):
        ptr = self.head

        if ptr is None:
            print("Lista vacia", end="")
        else:
            while ptr is not None:
                print(ptr.data, end="")
                print("->", end="")
                ptr = ptr.next
            print("NULL") 

MAXSIZE = 5
front = -1
rear = -1
listaEnlazada = LinkedList()

def Insertar():
    global front, rear
    
    print("\nIngrese el elemento: ", end="")
    elemento_str = input()

    try:
        elemento = int(elemento_str)
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
    
    listaEnlazada.LastInsert(elemento)
    print("\nElemento insertado correctamente.\n")

def Eliminar():
    global front, rear

    if front == -1 or front > rear:
        print("\nSUBDESBORDAMIENTO (UNDERFLOW)\n")
        return
    
    elemento = listaEnlazada.begin_delete()
    
    if front == rear:
        front = rear = -1
    else:
        front += 1
    
    print(f"\nElemento eliminado: {elemento}\n")

def Mostrar():
    if rear == -1 or front == -1 or front > rear:
        print("\nLa cola esta vacia.\n")
    else:
        print("\nElementos en la cola:\n")
        listaEnlazada.display()

opcion = 0

while opcion != 4:
    print("\n************************* MENU PRINCIPAL ***************************\n")
    print("======================================================================\n")
    print("1. Insertar un elemento\n")
    print("2. Eliminar un elemento\n")
    print("3. Mostrar La cola\n")
    print("4. Salir\n")
    opcion_str = input("Ingrese su opcion: ")

    try:
        opcion = int(opcion_str)
    except ValueError:
        opcion = -1

    if opcion == 1:
        Insertar()
    elif opcion == 2:
        Eliminar()
    elif opcion == 3:
        Mostrar()
    elif opcion == 4:
        print("\nSaliendo del programa...\n")
    else:
        print("\nOpcion invalida. Intente nuevamente.\n")