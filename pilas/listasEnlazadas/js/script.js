// Definición de la clase Node (Nodo)
class Node {
    constructor(dato) {
        this.data = dato;
        this.next = null;
    }
}

// Definición de la clase LinkedList (Lista Enlazada)
class LinkedList {
    constructor() {
        this.head = null;
        this.fin = null; //para no tener que estar recorriendo hasta lo ultimo y conectarlo directamente con el inicio
    }

    lastinsert(data) {
        const ptr = new Node(data);

        if (this.head === null) {
            ptr.next = this.head; // head es null, así que ptr.next es null
            this.head = ptr;
            this.fin = ptr;
        } else {
            this.fin.next = ptr;
            this.fin = ptr;
        }
    }

    last_delete() {
        let temp = this.head;
        if (this.head === null) {
            print("la lista esta vacia"); //nunca entraria
        } else if (this.head.next === this.head) { // Lógica idéntica a la de Java
            let numDeleted = this.fin.data;
            this.head = null;
            this.fin = null;
            return numDeleted;
        } else {
            let numDeleted = this.fin.data;

            // Manejo especial si hay solo un elemento (temp.next es null)
            if (temp.next === null) {
                this.head = null;
                this.fin = null;
                return numDeleted;
            }

            while (temp.next.next !== null) { //no se si funcionara (lógica idéntica)
                temp = temp.next;
            }
            this.fin = temp;
            this.fin.next = null; // Nota: Corregí un bug de tu lógica original (faltaba esto)
                                  // Si quieres el bug original, comenta la línea de arriba y descomenta la de abajo
            // this.fin = temp; // Esta es tu lógica original sin romper el enlace
            return numDeleted;
        }
        return null; // para que no se este quejando js
    }

    display() {
        if (this.fin === null) {
            return null; // Maneja el caso de pila vacía
        }
        return this.fin.data;
    }
}

// --- Lógica de la Pila (Stack) ---

// Configuración inicial del DOM y variables globales
const MAX_SIZE = 100;
let max = -1;
let lList = new LinkedList(); // Usamos nuestra LinkedList en lugar de un Array

const outputDiv = document.getElementById("output");

// Función para imprimir en el HTML
function print(message) {
    outputDiv.innerHTML += message + "<br>";
}

// Funciones de la Pila
function push(item) {
    if (max === MAX_SIZE - 1) {
        print("stack overflow");
        return;
    }
    max += 1;
    lList.lastinsert(item);
}

function pop() {
    if (max === -1) {
        print("Stack Underflow");
        return -1; // Devuelve -1 para concordar con peek()
    }
    max -= 1;
    return lList.last_delete();
}

function peek() {
    if (max === -1) {
        print("Pila vacia");
        return -1;
    }
    const data = lList.display();
    return data !== null ? data : -1;
}

function isEmpty() {
    return max === -1;
}

function isFull() {
    return max === MAX_SIZE - 1;
}

// --- Ejecución principal ---
push(10);
push(20);
push(30);

print("elemento superior: " + peek());
print("extrae elemento: " + pop());
print("elemento superior: " + peek());