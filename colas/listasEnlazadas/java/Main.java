import java.util.Scanner;

class Node<T> {
    public T data;
    public Node<T> next;

    public Node(T dato) {
        data = dato;
        next = null;
    }
}

class LinkedList<T> {
    private Node<T> head;
    private Node<T> fin;

    public LinkedList() {
        head = null;
        fin = null;
    }

    public void LastInsert(T data) {
        Node<T> ptr = new Node<T>(data);

        if (head == null) {
            ptr.next = head;
            head = ptr;
            fin = ptr;
        } else {
            fin.next = ptr;
            fin = ptr;
        }
    }

    public T begin_delete() {
        if (head == null) {
            System.out.println("la lista esta vacia");
        } else {
            T data = head.data;
            head = head.next;
            return data;
        }
        return null;
    }

    public void display() {
        Node<T> ptr;
        ptr = head;

        if (ptr == null) {
            System.out.print("Lista vacia");
        } else {
            while (ptr != null) {
                System.out.print(ptr.data);
                System.out.print("->");
                ptr = ptr.next;
            }
            System.out.print("NULL\n");
        }
    }
}

public class Main {
    private static final int MAXSIZE = 5;
    private static int front = -1, rear = -1;
    private static LinkedList<Integer> listaEnlazada = new LinkedList<Integer>();
    private static Scanner scanner = new Scanner(System.in);

    public static void Insertar() {
        int elemento;
        System.out.print("\nIngrese el elemento: ");

        // Manejo básico de errores de entrada
        try {
            elemento = Integer.parseInt(scanner.nextLine());
        } catch (NumberFormatException e) {
            System.out.println("\nEntrada no válida.\n");
            return;
        }

        if (rear == MAXSIZE - 1) {
            System.out.println("\nDESBORDAMIENTO (OVERFLOW)\n");
            return;
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        listaEnlazada.LastInsert(elemento);
        System.out.println("\nElemento insertado correctamente.\n");
    }

    public static void Eliminar() {
        if (front == -1 || front > rear) {
            System.out.println("\nSUBDESBORDAMIENTO (UNDERFLOW)\n");
            return;
        }
        int elemento = listaEnlazada.begin_delete();
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        System.out.println("\nElemento eliminado: " + elemento + "\n");
    }

    public static void Mostrar() {
        if (rear == -1 || front == -1 || front > rear) {
            System.out.println("\nLa cola esta vacia.\n");
        } else {
            System.out.println("\nElementos en la cola:\n");
            listaEnlazada.display();
        }
    }

    public static void main(String[] args) {
        int opcion = 0;

        while (opcion != 4) {
            System.out.println("\n************************* MENU PRINCIPAL ***************************\n");
            System.out.println("======================================================================\n");
            System.out.println("1. Insertar un elemento\n");
            System.out.println("2. Eliminar un elemento\n");
            System.out.println("3. Mostrar La cola\n");
            System.out.println("4. Salir\n");
            System.out.print("Ingrese su opcion: ");

            try {
                opcion = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
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
                    System.out.println("\nSaliendo del programa...\n");
                    break;
                default:
                    System.out.println("\nOpcion invalida. Intente nuevamente.\n");
                    break;
            }
        }
        scanner.close();
    }
}