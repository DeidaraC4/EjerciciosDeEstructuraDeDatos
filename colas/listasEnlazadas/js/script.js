class Node {
    constructor(dato) {
        this.data = dato;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
        this.fin = null;
    }

    LastInsert(data) {
        const ptr = new Node(data);

        if (this.head === null) {
            ptr.next = this.head;
            this.head = ptr;
            this.fin = ptr;
        } else {
            this.fin.next = ptr;
            this.fin = ptr;
        }
    }

    begin_delete() {
        if (this.head === null) {
            console.log("la lista esta vacia");
        } else {
            const data = this.head.data;
            this.head = this.head.next;
            return data;
        }
        return null;
    }

    display() {
        let ptr = this.head;
        let output = "";

        if (ptr === null) {
            output = "Lista vacia";
        } else {
            while (ptr !== null) {
                output += ptr.data + "->";
                ptr = ptr.next;
            }
            output += "NULL\n";
        }
        console.log(output);
    }
}

const MAXSIZE = 5;
let front = -1;
let rear = -1;
let listaEnlazada = new LinkedList();

function Insertar() {
    let elementoStr = prompt("\nIngrese el elemento: ");
    let elemento;

    if (elementoStr === null) return;
    
    elemento = parseInt(elementoStr);

    if (isNaN(elemento)) {
        console.log("\nEntrada no válida.\n");
        return;
    }

    if (rear === MAXSIZE - 1) {
        console.log("\nDESBORDAMIENTO (OVERFLOW)\n");
        return;
    }
    if (front === -1 && rear === -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    listaEnlazada.LastInsert(elemento);
    console.log("\nElemento insertado correctamente.\n");
}

function Eliminar() {
    if (front === -1 || front > rear) {
        console.log("\nSUBDESBORDAMIENTO (UNDERFLOW)\n");
        return;
    }
    let elemento = listaEnlazada.begin_delete();
    if (front === rear) {
        front = rear = -1;
    } else {
        front++;
    }
    console.log(`\nElemento eliminado: ${elemento}\n`);
}

function Mostrar() {
    if (rear === -1 || front === -1 || front > rear) {
        console.log("\nLa cola esta vacia.\n");
    } else {
        console.log("\nElementos en la cola:\n");
        listaEnlazada.display();
    }
}

let opcion = 0;

while (opcion !== 4) {
    let menu = "\n************************* MENU PRINCIPAL ***************************\n";
    menu += "======================================================================\n";
    menu += "1. Insertar un elemento\n";
    menu += "2. Eliminar un elemento\n";
    menu += "3. Mostrar La cola\n";
    menu += "4. Salir\n";
    menu += "Ingrese su opcion: ";

    let opcionStr = prompt(menu);

    if (opcionStr === null) {
        opcion = 4; 
    } else {
        opcion = parseInt(opcionStr);
    }
    
    if (isNaN(opcion)) {
        opcion = -1;
    }

    switch (opcion) {
        case 1:
            Insertar();
            break;
        case 2:
            Eliminar();
            break;
        case 3:
            Mostrar();
            break;
        case 4:
            console.log("\nSaliendo del programa...\n");
            break;
        default:
            console.log("\nOpcion invalida. Intente nuevamente.\n");
            break;
    }
}

front = -1;
rear = -1;
listaEnlazada = new LinkedList();
console.log("programa finalizado");