class Node {
    constructor() {
        this.data = null;
        this.next = null;
        this.prev = null;
    }
}

var head = null;

function main() {
    var choice = 0;
    while(choice != 9) {
        var menu = "\n********MENU PRINCIPAL********\n" +
                   "1. Insertar al inicio\n2. Insertar al final\n3. Insertar en posicion especifica\n" +
                   "4. Eliminar del inicio\n5. Eliminar del final\n6. Eliminar nodo en posicion\n" +
                   "7. Buscar elemento\n8. Mostrar lista\n9. Salir\n" +
                   "Ingrese su opcion: ";
        
        var input = prompt(menu);
        if(input === null) choice = 9;
        else choice = parseInt(input);

        switch(choice) {
            case 1: begin_insert(); break;
            case 2: last_insert(); break;
            case 3: random_insert(); break;
            case 4: begin_delete(); break;
            case 5: last_delete(); break;
            case 6: random_delete(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: console.log("Saliendo del programa...\n"); break;
            default: console.log("Opcion no valida\n");
        }
    }
}

function begin_insert() {
    var ptr = new Node();
    var item;
    
    item = parseInt(prompt("Ingrese valor: "));
    
    ptr.data = item;
    
    if(head == null) {
        ptr.next = ptr;
        ptr.prev = ptr;
        head = ptr;
    } else {
        var fin = head.prev;
        ptr.next = head;
        ptr.prev = fin;
        fin.next = ptr;
        head.prev = ptr;
        head = ptr;
    }
    console.log("Nodo insertado al inicio\n");
}

function last_insert() {
    var ptr = new Node();
    var item;

    item = parseInt(prompt("Ingrese valor: "));

    ptr.data = item;

    if(head == null) {
        ptr.next = ptr;
        ptr.prev = ptr;
        head = ptr;
    } else {
        var fin = head.prev;
        ptr.next = head;
        ptr.prev = fin;
        fin.next = ptr;
        head.prev = ptr;
    }
    console.log("Nodo insertado al final\n");
}

function random_insert() {
    var pos, item, i = 0;
    var ptr = new Node();
    var temp;

    if(head == null) {
        console.log("Lista vacia, inserte primero un nodo\n");
        return;
    }

    pos = parseInt(prompt("Ingrese posicion despues de la cual insertar: "));
    item = parseInt(prompt("Ingrese valor: "));

    ptr.data = item;

    temp = head;
    for(i = 0; i < pos; i++) {
        temp = temp.next;
        if(temp == head) { 
            console.log("Posicion fuera de rango\n");
            return;
        }
    }

    ptr.next = temp.next;
    ptr.prev = temp;
    temp.next.prev = ptr;
    temp.next = ptr;

    console.log("Nodo insertado despues de la posicion " + pos + "\n");
}

function begin_delete() {
    if(head == null) {
        console.log("Lista vacia\n");
        return;
    }

    var fin = head.prev;

    if(head.next == head) {
        head = null;
    } else {
        fin.next = head.next;
        head.next.prev = fin;
        head = head.next;
    }
    console.log("Nodo eliminado del inicio\n");
}

function last_delete() {
    if(head == null) {
        console.log("Lista vacia\n");
        return;
    }

    var fin = head.prev;

    if(head.next == head) {
        head = null;
    } else {
        fin.prev.next = head;
        head.prev = fin.prev;
    }
    console.log("Nodo eliminado del final\n");
}

function random_delete() {
    var pos, i = 0;
    var temp;

    if(head == null) {
        console.log("Lista vacia\n");
        return;
    }

    pos = parseInt(prompt("Ingrese posicion del nodo a eliminar: "));

    temp = head;
    for(i = 0; i < pos; i++) {
        temp = temp.next;
        if(temp == head) {
            console.log("Posicion fuera de rango\n");
            return;
        }
    }

    if(temp.next == temp && temp.prev == temp) {
        head = null;
        return;
    }
    if(temp == head) head = head.next;

    temp.prev.next = temp.next;
    temp.next.prev = temp.prev;

    console.log("Nodo eliminado en la posicion " + pos + "\n");
}

function search() {
    if(head == null) {
        console.log("Lista vacia\n");
        return;
    }

    var item, i = 0;
    var found = false;
    var temp = head;

    item = parseInt(prompt("Ingrese elemento a buscar: "));

    do {
        if(temp.data == item) {
            console.log("Elemento encontrado en la posicion " + i + "\n");
            found = true;
            break;
        }
        temp = temp.next;
        i++;
    } while(temp != head);

    if(!found) console.log("Elemento no encontrado\n");
}

function display() {
    if(head == null) {
        console.log("Lista vacia\n");
        return;
    }

    var temp = head;
    var output = "Lista: ";
    do {
        output += temp.data + " <-> ";
        temp = temp.next;
    } while(temp != head);
    output += "(circular)\n";
    console.log(output);
}