import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node prev;

    public Node(int dato) {
        this.data = dato;
        this.next = null;
        this.prev = null;
    }
}

class LinkedList {
    Node head;

    public LinkedList() {
        this.head = null;
    }

    public void beginsert(int data) {
        Node ptr = new Node(data);
        if (this.head == null) {
            this.head = ptr;
        } else {
            ptr.next = this.head;
            this.head.prev = ptr;
            this.head = ptr;
        }
        System.out.println("Nodo insertado al inicio.");
    }

    public void lastinsert(int data) {
        Node ptr = new Node(data);
        if (this.head == null) {
            ptr.next = this.head;
            this.head = ptr;
        } else {
            Node temp = this.head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = ptr;
            ptr.prev = temp;
        }
        System.out.println("Nodo insertado al final.");
    }

    public void randominsert(int data, int loc) {
        Node ptr = new Node(data);
        Node temp = this.head;

        if (loc == 0) {
            ptr.next = head;
            if (head != null) {
                head.prev = ptr;
            }
            head = ptr;
        } else {
            for (int i = 0; i < loc; i++) {
                temp = temp.next;
                if (temp == null) {
                    System.out.println("no se pudo alcanzar dicha locacion");
                    return;
                }
            }
            ptr.next = temp.next;
            if (temp.next != null) {
                temp.next.prev = ptr;
            }
            temp.next = ptr;
            ptr.prev = temp;
        }
        System.out.println("Nodo insertado en la posicion " + loc + ".");
    }

    public void begin_delete() {
        if (this.head == null) {
            System.out.println("la lista esta vacia");
        } else if (this.head.next == null) {
            this.head = null;
        } else {
            this.head = this.head.next;
            this.head.prev = null;
            System.out.println("Primer nodo eliminado.");
        }
    }

    public void last_delete() {
        Node temp = this.head;
        if (this.head == null) {
            System.out.println("la lista esta vacia");
        } else if (this.head.next == null) {
            this.head = null;
            System.out.println("Ultimo nodo eliminado (la lista ahora esta vacia).");
        } else {
            while (temp.next.next != null) {
                temp = temp.next;
            }
            temp.next = null;
            System.out.println("Ultimo nodo eliminado.");
        }
    }

    public void random_delete(int loc) {
        if (this.head == null) {
            System.out.println("la lista esta vacia");
        } else {
            Node temp = this.head;
            Node temp2 = null;
            if (loc == 0) {
                if (this.head.next == null) {
                    this.head = null;
                    return;
                }
                this.head = this.head.next;
                this.head.prev = null;
            } else {
                for (int i = 0; i < loc; i++) {
                    temp2 = temp;
                    temp = temp.next;
                    if (temp == null) {
                        System.out.println("eliminacion fuera de rango");
                        return;
                    }
                }
                temp2.next = temp.next;
                if (temp.next != null) {
                    temp.next.prev = temp2;
                }
            }
            System.out.println("Nodo en la posicion " + loc + " eliminado.");
        }
    }

    public void search(int ele) {
        Node temp = this.head;
        int loc = 0;
        boolean found = false;
        if (this.head == null) {
            System.out.println("La lista esta vacia");
        } else {
            while (temp != null) {
                if (temp.data == ele) {
                    found = true;
                    break;
                }
                temp = temp.next;
                loc += 1;
            }
            if (found) {
                System.out.println("elemento " + ele + " encontrado en la posicion  " + loc);
            } else {
                System.out.println("Elemento " + ele + " NO encontrado en la lista.");
            }
        }
    }

    public void display() {
        Node ptr = this.head;
        if (this.head == null) {
            System.out.println("Lista vacia");
        } else {
            String output = "";
            while (ptr != null) {
                output += ptr.data + "<->";
                ptr = ptr.next;
            }
            output += "NULL";
            System.out.println(output);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList lista = new LinkedList();
        int choice = 0;
        int ele = 0;
        int ele2 = 0;
        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("\n\n*********Menu principal*********");
            System.out.println("\nElige una opcion de la siguiente lista ...");
            System.out.println("\n===============================================");
            System.out.println("\n1. insertar al principio\n2. insertar al final\n3. insertar\n4. eliminar al principio");
            System.out.println("\n5. eliminar el ultimo\n6. eliminar nodo despues de la ubicacion especificada\n7. buscar un elemento\n8. mostrar\n9. salir");
            System.out.println("\nIngrese su opcion?");

            if (sc.hasNextInt()) {
                choice = sc.nextInt();
            } else {
                sc.next();
                System.out.println("Entrada invalida. Por favor ingrese un numero.");
                continue;
            }

            switch (choice) {
                case 1:
                    System.out.println("Escribe un elemento a agregar");
                    ele = sc.nextInt();
                    lista.beginsert(ele);
                    break;
                case 2:
                    System.out.println("Escribe un elemento a agregar");
                    ele = sc.nextInt();
                    lista.lastinsert(ele);
                    break;
                case 3:
                    System.out.println("Escribe un elemento a agregar");
                    ele = sc.nextInt();
                    System.out.println("Escribe la posicion donde se va a agregar");
                    ele2 = sc.nextInt();
                    lista.randominsert(ele, ele2);
                    break;
                case 4:
                    lista.begin_delete();
                    break;
                case 5:
                    lista.last_delete();
                    break;
                case 6:
                    System.out.println("Escribe la posicion del elemento a eliminar");
                    ele = sc.nextInt();
                    lista.random_delete(ele);
                    break;
                case 7:
                    System.out.println("Escribe un elemento a buscar");
                    ele = sc.nextInt();
                    lista.search(ele);
                    break;
                case 8:
                    lista.display();
                    break;
                case 9:
                    System.out.println("saliendo del programa");
                    break;
                default:
                    System.out.println("Opcion invalida introduzca una opcion valida");
                    break;
            }
        } while (choice != 9);
        sc.close();
    }
}