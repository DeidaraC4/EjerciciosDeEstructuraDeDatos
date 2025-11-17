import sys

class Node:
    def __init__(self):
        self.data = None
        self.next = None
        self.prev = None

head = None

def begin_insert():
    global head
    ptr = Node()
    print("Ingrese valor: ")
    item = int(input())
    
    ptr.data = item
    
    if head is None:
        ptr.next = ptr
        ptr.prev = ptr
        head = ptr
    else:
        fin = head.prev
        ptr.next = head
        ptr.prev = fin
        fin.next = ptr
        head.prev = ptr
        head = ptr
    print("Nodo insertado al inicio\n")

def last_insert():
    global head
    ptr = Node()
    print("Ingrese valor: ")
    item = int(input())

    ptr.data = item

    if head is None:
        ptr.next = ptr
        ptr.prev = ptr
        head = ptr
    else:
        fin = head.prev
        ptr.next = head
        ptr.prev = fin
        fin.next = ptr
        head.prev = ptr
    print("Nodo insertado al final\n")

def random_insert():
    global head
    if head is None:
        print("Lista vacia, inserte primero un nodo\n")
        return

    print("Ingrese posicion despues de la cual insertar: ")
    pos = int(input())
    print("Ingrese valor: ")
    item = int(input())

    ptr = Node()
    ptr.data = item

    temp = head
    for i in range(pos):
        temp = temp.next
        if temp == head:
            print("Posicion fuera de rango\n")
            return

    ptr.next = temp.next
    ptr.prev = temp
    temp.next.prev = ptr
    temp.next = ptr

    print("Nodo insertado despues de la posicion " + str(pos) + "\n")

def begin_delete():
    global head
    if head is None:
        print("Lista vacia\n")
        return

    fin = head.prev

    if head.next == head:
        head = None
    else:
        fin.next = head.next
        head.next.prev = fin
        head = head.next
    print("Nodo eliminado del inicio\n")

def last_delete():
    global head
    if head is None:
        print("Lista vacia\n")
        return

    fin = head.prev

    if head.next == head:
        head = None
    else:
        fin.prev.next = head
        head.prev = fin.prev
    print("Nodo eliminado del final\n")

def random_delete():
    global head
    if head is None:
        print("Lista vacia\n")
        return

    print("Ingrese posicion del nodo a eliminar: ")
    pos = int(input())

    temp = head
    for i in range(pos):
        temp = temp.next
        if temp == head:
            print("Posicion fuera de rango\n")
            return

    if temp.next == temp and temp.prev == temp:
        head = None
        return
    
    if temp == head:
        head = head.next

    temp.prev.next = temp.next
    temp.next.prev = temp.prev

    print("Nodo eliminado en la posicion " + str(pos) + "\n")

def search():
    global head
    if head is None:
        print("Lista vacia\n")
        return

    i = 0
    found = False
    temp = head

    print("Ingrese elemento a buscar: ")
    item = int(input())

    while True:
        if temp.data == item:
            print("Elemento encontrado en la posicion " + str(i) + "\n")
            found = True
            break
        temp = temp.next
        i += 1
        if temp == head:
            break

    if not found:
        print("Elemento no encontrado\n")

def display():
    global head
    if head is None:
        print("Lista vacia\n")
        return

    temp = head
    print("Lista: ", end="")
    while True:
        print(str(temp.data) + " <-> ", end="")
        temp = temp.next
        if temp == head:
            break
    print("(circular)\n")

choice = 0
while choice != 9:
    print("\n********MENU PRINCIPAL********\n")
    print("1. Insertar al inicio\n2. Insertar al final\n3. Insertar en posicion especifica\n")
    print("4. Eliminar del inicio\n5. Eliminar del final\n6. Eliminar nodo en posicion\n")
    print("7. Buscar elemento\n8. Mostrar lista\n9. Salir\n")
    print("Ingrese su opcion: ")
    
    try:
        choice = int(input())
    except ValueError:
        choice = 0

    if choice == 1: begin_insert()
    elif choice == 2: last_insert()
    elif choice == 3: random_insert()
    elif choice == 4: begin_delete()
    elif choice == 5: last_delete()
    elif choice == 6: random_delete()
    elif choice == 7: search()
    elif choice == 8: display()
    elif choice == 9: print("Saliendo del programa...\n")
    else: print("Opcion no valida\n")
