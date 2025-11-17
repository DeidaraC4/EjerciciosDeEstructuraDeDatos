class Node {
    constructor(dato) {
        this.data = dato;
        this.next = null;
        this.prev = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    beginsert(data) {
        let ptr = new Node(data);
        if (this.head === null) {
            this.head = ptr;
        } else {
            ptr.next = this.head;
            this.head.prev = ptr;
            this.head = ptr;
        }
        console.log("Nodo insertado al inicio.");
    }

    lastinsert(data) {
        let ptr = new Node(data);
        if (this.head === null) {
            ptr.next = this.head;
            this.head = ptr;
        } else {
            let temp = this.head;
            while (temp.next !== null) {
                temp = temp.next;
            }
            temp.next = ptr;
            ptr.prev = temp;
        }
        console.log("Nodo insertado al final.");
    }

    randominsert(data, loc) {
        let ptr = new Node(data);
        let temp = this.head;

        if (loc === 0) {
            ptr.next = this.head;
            if (this.head !== null) {
                this.head.prev = ptr;
            }
            this.head = ptr;
        } else {
            for (let i = 0; i < loc; i++) {
                temp = temp.next;
                if (temp === null) {
                    console.log("no se pudo alcanzar dicha locacion");
                    return;
                }
            }
            ptr.next = temp.next;
            if (temp.next !== null) temp.next.prev = ptr;
            temp.next = ptr;
            ptr.prev = temp;
        }
        console.log(`Nodo insertado en la posicion ${loc}.`);
    }

    begin_delete() {
        if (this.head === null) {
            console.log("la lista esta vacia");
        } else if (this.head.next === null) {
            this.head = null;
        } else {
            this.head = this.head.next;
            this.head.prev = null;
            console.log("Primer nodo eliminado.");
        }
    }

    last_delete() {
        let temp = this.head;
        if (this.head === null) {
            console.log("la lista esta vacia");
        } else if (this.head.next === null) {
            this.head = null;
            console.log("Ultimo nodo eliminado (la lista ahora esta vacia).");
        } else {
            while (temp.next.next !== null) {
                temp = temp.next;
            }
            temp.next = null;
            console.log("Ultimo nodo eliminado.");
        }
    }

    random_delete(loc) {
        if (this.head === null) {
            console.log("la lista esta vacia");
        } else {
            let temp = this.head;
            let temp2;
            if (loc === 0) {
                if (this.head.next === null) {
                    this.head = null;
                    return;
                }
                this.head = this.head.next;
                this.head.prev = null;
            } else {
                for (let i = 0; i < loc; i++) {
                    temp2 = temp;
                    temp = temp.next;
                    if (temp === null) {
                        console.log("eliminacion fuera de rango");
                        return;
                    }
                }
                temp2.next = temp.next;
                if (temp.next !== null) {
                    temp.next.prev = temp2;
                }
            }
            console.log(`Nodo en la posicion ${loc} eliminado.`);
        }
    }

    search(ele) {
        let temp = this.head;
        let loc = 0;
        let found = false;
        if (this.head === null) {
            console.log("La lista esta vacia");
        } else {
            while (temp !== null) {
                if (temp.data === ele) {
                    found = true;
                    break;
                }
                temp = temp.next;
                loc += 1;
            }
            if (found) {
                console.log(`elemento ${ele} encontrado en la posicion  ${loc}`);
            } else {
                console.log(`Elemento ${ele} NO encontrado en la lista.`);
            }
        }
    }

    display() {
        let ptr = this.head;
        if (this.head === null) {
            console.log("Lista vacia");
        } else {
            let output = "";
            while (ptr !== null) {
                output += `${ptr.data}<->`;
                ptr = ptr.next;
            }
            output += "NULL";
            console.log(output);
        }
    }
}

function main() {
    let lista = new LinkedList();
    let choice = 0;
    let ele = 0;
    let ele2 = 0;

    do {
        let menu = "\n\n*********Menu principal*********\n"
             + "\nElige una opcion de la siguiente lista ...\n"
             + "\n===============================================\n"
             + "\n1. insertar al principio\n2. insertar al final\n3. insertar\n4. eliminar al principio"
             + "\n5. eliminar el ultimo\n6. eliminar nodo despues de la ubicacion especificada\n7. buscar un elemento\n8. mostrar\n9. salir\n"
             + "\nIngrese su opcion?\n";
        
        let input = prompt(menu);
        if(input === null) choice = 9;
        else choice = parseInt(input);

        if (isNaN(choice)) {
            console.log("Entrada invalida. Por favor ingrese un numero.");
            continue;
        }

        switch (choice) {
            case 1:
                ele = parseInt(prompt("Escribe un elemento a agregar"));
                lista.beginsert(ele);
                break;
            case 2:
                ele = parseInt(prompt("Escribe un elemento a agregar"));
                lista.lastinsert(ele);
                break;
            case 3:
                ele = parseInt(prompt("Escribe un elemento a agregar"));
                ele2 = parseInt(prompt("Escribe la posicion donde se va a agregar"));
                lista.randominsert(ele, ele2);
                break;
            case 4:
                lista.begin_delete();
                break;
            case 5:
                lista.last_delete();
                break;
            case 6:
                ele = parseInt(prompt("Escribe la posicion del elemento a eliminar"));
                lista.random_delete(ele);
                break;
            case 7:
                ele = parseInt(prompt("Escribe un elemento a buscar"));
                lista.search(ele);
                break;
            case 8:
                lista.display();
                break;
            case 9:
                console.log("saliendo del programa");
                break;
            default:
                console.log("Opcion invalida introduzca una opcion valida");
                break;
        }
    } while (choice !== 9);
}