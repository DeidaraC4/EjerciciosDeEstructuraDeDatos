using System;

class Node {
    public int data;
    public Node next;
    public Node prev;
}

class Program {
    static Node head = null;

    static void Main(string[] args) {
        int choice = 0;
        while(choice != 9) {
            Console.WriteLine("\n********MENU PRINCIPAL********\n");
            Console.WriteLine("1. Insertar al inicio\n2. Insertar al final\n3. Insertar en posicion especifica\n");
            Console.WriteLine("4. Eliminar del inicio\n5. Eliminar del final\n6. Eliminar nodo en posicion\n");
            Console.WriteLine("7. Buscar elemento\n8. Mostrar lista\n9. Salir\n");
            Console.Write("Ingrese su opcion: ");
            
            if (!int.TryParse(Console.ReadLine(), out choice)) {
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
                case 9: Console.WriteLine("Saliendo del programa...\n"); break;
                default: Console.WriteLine("Opcion no valida\n"); break;
            }
        }
    }

    static void begin_insert() {
        Node ptr = new Node();
        int item;
        
        Console.Write("Ingrese valor: ");
        item = int.Parse(Console.ReadLine());
        
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
        Console.WriteLine("Nodo insertado al inicio\n");
    }

    static void last_insert() {
        Node ptr = new Node();
        int item;

        Console.Write("Ingrese valor: ");
        item = int.Parse(Console.ReadLine());

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
        Console.WriteLine("Nodo insertado al final\n");
    }

    static void random_insert() {
        int pos, item, i = 0;
        Node ptr = new Node();
        Node temp;

        if(head == null) {
            Console.WriteLine("Lista vacia, inserte primero un nodo\n");
            return;
        }

        Console.Write("Ingrese posicion despues de la cual insertar: ");
        pos = int.Parse(Console.ReadLine());
        Console.Write("Ingrese valor: ");
        item = int.Parse(Console.ReadLine());

        ptr.data = item;

        temp = head;
        for(i = 0; i < pos; i++) {
            temp = temp.next;
            if(temp == head) { 
                Console.WriteLine("Posicion fuera de rango\n");
                return;
            }
        }

        ptr.next = temp.next;
        ptr.prev = temp;
        temp.next.prev = ptr;
        temp.next = ptr;

        Console.WriteLine("Nodo insertado despues de la posicion " + pos + "\n");
    }

    static void begin_delete() {
        if(head == null) {
            Console.WriteLine("Lista vacia\n");
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
        Console.WriteLine("Nodo eliminado del inicio\n");
    }

    static void last_delete() {
        if(head == null) {
            Console.WriteLine("Lista vacia\n");
            return;
        }

        Node fin = head.prev;

        if(head.next == head) {
            head = null;
        } else {
            fin.prev.next = head;
            head.prev = fin.prev;
        }
        Console.WriteLine("Nodo eliminado del final\n");
    }

    static void random_delete() {
        int pos, i = 0;
        Node temp;

        if(head == null) {
            Console.WriteLine("Lista vacia\n");
            return;
        }

        Console.Write("Ingrese posicion del nodo a eliminar: ");
        pos = int.Parse(Console.ReadLine());

        temp = head;
        for(i = 0; i < pos; i++) {
            temp = temp.next;
            if(temp == head) {
                Console.WriteLine("Posicion fuera de rango\n");
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

        Console.WriteLine("Nodo eliminado en la posicion " + pos + "\n");
    }

    static void search() {
        if(head == null) {
            Console.WriteLine("Lista vacia\n");
            return;
        }

        int item, i = 0;
        bool found = false;
        Node temp = head;

        Console.Write("Ingrese elemento a buscar: ");
        item = int.Parse(Console.ReadLine());

        do {
            if(temp.data == item) {
                Console.WriteLine("Elemento encontrado en la posicion " + i + "\n");
                found = true;
                break;
            }
            temp = temp.next;
            i++;
        } while(temp != head);

        if(!found) Console.WriteLine("Elemento no encontrado\n");
    }

    static void display() {
        if(head == null) {
            Console.WriteLine("Lista vacia\n");
            return;
        }

        Node temp = head;
        Console.Write("Lista: ");
        do {
            Console.Write(temp.data + " <-> ");
            temp = temp.next;
        } while(temp != head);
        Console.WriteLine("(circular)\n");
    }
}