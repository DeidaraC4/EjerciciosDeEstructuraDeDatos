class Node:
    def __init__(self, dato):
        self.data = dato
        self.next = None
        self.prev = None

class LinkedList:
    def __init__(self):
        self.head = None

    def beginsert(self, data):
        ptr = Node(data)
        if self.head is None:
            self.head = ptr
        else:
            ptr.next = self.head
            self.head.prev = ptr
            self.head = ptr
        print("Nodo insertado al inicio.")

    def lastinsert(self, data):
        ptr = Node(data)
        if self.head is None:
            ptr.next = self.head
            self.head = ptr
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = ptr
            ptr.prev = temp
        print("Nodo insertado al final.")

    def randominsert(self, data, loc):
        ptr = Node(data)
        temp = self.head

        if loc == 0:
            ptr.next = self.head
            if self.head is not None:
                self.head.prev = ptr
            self.head = ptr
        else:
            for i in range(loc):
                temp = temp.next
                if temp is None:
                    print("no se pudo alcanzar dicha locacion")
                    return
            ptr.next = temp.next
            if temp.next is not None:
                temp.next.prev = ptr
            temp.next = ptr
            ptr.prev = temp
        print(f"Nodo insertado en la posicion {loc}.")

    def begin_delete(self):
        if self.head is None:
            print("la lista esta vacia")
        elif self.head.next is None:
            self.head = None
        else:
            self.head = self.head.next
            self.head.prev = None
            print("Primer nodo eliminado.")

    def last_delete(self):
        temp = self.head
        if self.head is None:
            print("la lista esta vacia")
        elif self.head.next is None:
            self.head = None
            print("Ultimo nodo eliminado (la lista ahora esta vacia).")
        else:
            while temp.next.next is not None:
                temp = temp.next
            temp.next = None
            print("Ultimo nodo eliminado.")

    def random_delete(self, loc):
        if self.head is None:
            print("la lista esta vacia")
        else:
            temp = self.head
            temp2 = None
            if loc == 0:
                if self.head.next is None:
                    self.head = None
                    return
                self.head = self.head.next
                self.head.prev = None
            else:
                for i in range(loc):
                    temp2 = temp
                    temp = temp.next
                    if temp is None:
                        print("eliminacion fuera de rango")
                        return
                temp2.next = temp.next
                if temp.next is not None:
                    temp.next.prev = temp2
            print(f"Nodo en la posicion {loc} eliminado.")

    def search(self, ele):
        temp = self.head
        loc = 0
        found = False
        if self.head is None:
            print("La lista esta vacia")
        else:
            while temp is not None:
                if temp.data == ele:
                    found = True
                    break
                temp = temp.next
                loc += 1
            if found:
                print(f"elemento {ele} encontrado en la posicion  {loc}")
            else:
                print(f"Elemento {ele} NO encontrado en la lista.")

    def display(self):
        ptr = self.head
        if self.head is None:
            print("Lista vacia")
        else:
            output = ""
            while ptr is not None:
                output += f"{ptr.data}<->"
                ptr = ptr.next
            output += "NULL"
            print(output)

lista = LinkedList()
choice = 0
ele = 0
ele2 = 0

while choice != 9:
    print("\n\n*********Menu principal*********")
    print("\nElige una opcion de la siguiente lista ...")
    print("\n===============================================")
    print("\n1. insertar al principio\n2. insertar al final\n3. insertar\n4. eliminar al principio")
    print("\n5. eliminar el ultimo\n6. eliminar nodo despues de la ubicacion especificada\n7. buscar un elemento\n8. mostrar\n9. salir")
    print("\nIngrese su opcion?")

    try:
        choice = int(input())
    except ValueError:
        print("Entrada invalida. Por favor ingrese un numero.")
        continue

    if choice == 1:
        print("Escribe un elemento a agregar")
        ele = int(input())
        lista.beginsert(ele)
    elif choice == 2:
        print("Escribe un elemento a agregar")
        ele = int(input())
        lista.lastinsert(ele)
    elif choice == 3:
        print("Escribe un elemento a agregar")
        ele = int(input())
        print("Escribe la posicion donde se va a agregar")
        ele2 = int(input())
        lista.randominsert(ele, ele2)
    elif choice == 4:
        lista.begin_delete()
    elif choice == 5:
        lista.last_delete()
    elif choice == 6:
        print("Escribe la posicion del elemento a eliminar")
        ele = int(input())
        lista.random_delete(ele)
    elif choice == 7:
        print("Escribe un elemento a buscar")
        ele = int(input())
        lista.search(ele)
    elif choice == 8:
        lista.display()
    elif choice == 9:
        print("saliendo del programa")
    else:
        print("Opcion invalida introduzca una opcion valida")