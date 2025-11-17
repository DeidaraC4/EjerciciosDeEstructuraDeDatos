import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node prev;
}

public class Main {
    static Node head = null;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int choice = 0;
        while(choice != 9) {
            System.out.println("\n********MENU PRINCIPAL********\n");
            System.out.println("1. Insertar al inicio\n2. Insertar al final\n3. Insertar en posicion especifica\n");
            System.out.println("4. Eliminar del inicio\n5. Eliminar del final\n6. Eliminar nodo en posicion\n");
            System.out.println("7. Buscar elemento\n8. Mostrar lista\n9. Salir\n");
            System.out.print("Ingrese su opcion: ");
            
            try {
                choice = Integer.parseInt(sc.next());
            } catch (NumberFormatException e) {
                choice = 0;
            }

            switch(choice) {
                case 1: begin_insert(); break;
                case 2: last_insert(); break;
                case 3: random_insert(); break;
                case 4: begin_delete(); break;
                case 5: last_delete(); break;
                case 6: random_delete(); break;
                case 7: search(); break;
                case 8: display(); break;
                case 9: System.out.println("Saliendo del programa...\n"); break;
                default: System.out.println("Opcion no valida\n");
            }
        }
    }

    static void begin_insert() {
        Node ptr = new Node();
        int item;
        
        System.out.print("Ingrese valor: ");
        item = sc.nextInt();
        
        ptr.data = item;
        
        if(head == null) {
            ptr.next = ptr;
            ptr.prev = ptr;
            head = ptr;
        } else {
            Node fin = head.prev;
            ptr.next = head;
            ptr.prev = fin;
            fin.next = ptr;
            head.prev = ptr;
            head = ptr;
        }
        System.out.println("Nodo insertado al inicio\n");
    }

    static void last_insert() {
        Node ptr = new Node();
        int item;

        System.out.print("Ingrese valor: ");
        item = sc.nextInt();

        ptr.data = item;

        if(head == null) {
            ptr.next = ptr;
            ptr.prev = ptr;
            head = ptr;
        } else {
            Node fin = head.prev;
            ptr.next = head;
            ptr.prev = fin;
            fin.next = ptr;
            head.prev = ptr;
        }
        System.out.println("Nodo insertado al final\n");
    }

    static void random_insert() {
        int pos, item, i = 0;
        Node ptr = new Node();
        Node temp;

        if(head == null) {
            System.out.println("Lista vacia, inserte primero un nodo\n");
            return;
        }

        System.out.print("Ingrese posicion despues de la cual insertar: ");
        pos = sc.nextInt();
        System.out.print("Ingrese valor: ");
        item = sc.nextInt();

        ptr.data = item;

        temp = head;
        for(i = 0; i < pos; i++) {
            temp = temp.next;
            if(temp == head) { 
                System.out.println("Posicion fuera de rango\n");
                return;
            }
        }

        ptr.next = temp.next;
        ptr.prev = temp;
        temp.next.prev = ptr;
        temp.next = ptr;

        System.out.println("Nodo insertado despues de la posicion " + pos + "\n");
    }

    static void begin_delete() {
        if(head == null) {
            System.out.println("Lista vacia\n");
            return;
        }

        Node fin = head.prev;

        if(head.next == head) {
            head = null;
        } else {
            fin.next = head.next;
            head.next.prev = fin;
            head = head.next;
        }
        System.out.println("Nodo eliminado del inicio\n");
    }

    static void last_delete() {
        if(head == null) {
            System.out.println("Lista vacia\n");
            return;
        }

        Node fin = head.prev;

        if(head.next == head) {
            head = null;
        } else {
            fin.prev.next = head;
            head.prev = fin.prev;
        }
        System.out.println("Nodo eliminado del final\n");
    }

    static void random_delete() {
        int pos, i = 0;
        Node temp;

        if(head == null) {
            System.out.println("Lista vacia\n");
            return;
        }

        System.out.print("Ingrese posicion del nodo a eliminar: ");
        pos = sc.nextInt();

        temp = head;
        for(i = 0; i < pos; i++) {
            temp = temp.next;
            if(temp == head) {
                System.out.println("Posicion fuera de rango\n");
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

        System.out.println("Nodo eliminado en la posicion " + pos + "\n");
    }

    static void search() {
        if(head == null) {
            System.out.println("Lista vacia\n");
            return;
        }

        int item, i = 0;
        boolean found = false;
        Node temp = head;

        System.out.print("Ingrese elemento a buscar: ");
        item = sc.nextInt();

        do {
            if(temp.data == item) {
                System.out.println("Elemento encontrado en la posicion " + i + "\n");
                found = true;
                break;
            }
            temp = temp.next;
            i++;
        } while(temp != head);

        if(!found) System.out.println("Elemento no encontrado\n");
    }

    static void display() {
        if(head == null) {
            System.out.println("Lista vacia\n");
            return;
        }

        Node temp = head;
        System.out.print("Lista: ");
        do {
            System.out.print(temp.data + " <-> ");
            temp = temp.next;
        } while(temp != head);
        System.out.println("(circular)\n");
    }
}