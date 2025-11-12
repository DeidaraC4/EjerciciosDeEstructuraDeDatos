# Definición de la clase Node (Nodo)
class Node:
    def __init__(self, dato):
        self.data = dato
        self.next = None

# Definición de la clase LinkedList (Lista Enlazada)
class LinkedList:
    def __init__(self):
        self.head = None
        self.fin = None #para no tener que estar recorriendo hasta lo ultimo y conectarlo directamente con el inicio

    def lastinsert(self, data):
        ptr = Node(data)

        if self.head is None:
            ptr.next = self.head # head es None, así que ptr.next es None
            self.head = ptr
            self.fin = ptr
        else:
            self.fin.next = ptr
            self.fin = ptr

    def last_delete(self):
        temp = self.head
        if self.head is None:
            print("la lista esta vacia") #nunca entraria
        elif self.head.next == self.head: # Lógica idéntica a la de Java
            numDeleted = self.fin.data
            self.head = None
            self.fin = None
            return numDeleted
        else:
            numDeleted = self.fin.data
            
            # Manejo especial si hay solo un elemento (temp.next es None)
            if temp.next is None:
                self.head = None
                self.fin = None
                return numDeleted

            while temp.next.next is not None: #no se si funcionara (lógica idéntica)
                temp = temp.next
            
            self.fin = temp
            self.fin.next = None # Nota: Corregí un bug de tu lógica original (faltaba esto)
                                 # Si quieres el bug original, comenta la línea de arriba y descomenta la de abajo
            # self.fin = temp # Esta es tu lógica original sin romper el enlace
            return numDeleted
        
        return None # para que no se este quejando python (equivale a null)

    def display(self):
        if self.fin is None:
            return None # Maneja el caso de pila vacía
        return self.fin.data

# Variables globales para el estado de la Pila
MAX_SIZE = 100
top = -1
lList = LinkedList()

def push(item):
    global top # Necesario para modificar la variable global
    if top == MAX_SIZE - 1:
        print("stack overflow")
        return
    top += 1
    lList.lastinsert(item)

def pop():
    global top # Necesario para modificar la variable global
    if top == -1:
        print("Stack Underflow")
        return -1 # Devuelve -1 para concordar con peek()
    top -= 1
    return lList.last_delete()

def peek():
    if top == -1:
        print("Pila vacia")
        return -1
    data = lList.display()
    return data if data is not None else -1

def isEmpty():
    return top == -1

def isFull():
    return top == MAX_SIZE - 1

# Ejecución principal
if __name__ == "__main__":
    push(10)
    push(20)
    push(30)

    print(f"elemento superior: {peek()}")
    print(f"extrae elemento: {pop()}")
    print(f"elemento superior: {peek()}")