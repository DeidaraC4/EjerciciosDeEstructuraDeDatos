using System;

public class Node<T>
{
    public T data;
    public Node<T> next;

    public Node(T dato)
    {
        data = dato;
        next = null;
    }
}

public class LinkedList<T>
{
    private Node<T> head;
    private Node<T> fin;

    public LinkedList()
    {
        head = null;
        fin = null;
    }

    public void LastInsert(T data)
    {
        Node<T> ptr = new Node<T>(data);

        if (head == null)
        {
            ptr.next = head;
            head = ptr;
            fin = ptr;
        }
        else
        {
            fin.next = ptr;
            fin = ptr;
        }
    }

    public T begin_delete()
        {
            if(head == null)
            {
                Console.WriteLine("la lista esta vacia");
            }
            else
            {
                T data = head.data;
                head = head.next;
                return data;
            }
            return default;
        }

    public void display()
    {
        Node<T> ptr;
        ptr = head;

        if (ptr == null)
        {
            Console.Write("Lista vacia");
        }else{
            while(ptr != null){
                Console.Write(ptr.data);
                Console.Write("->");
                ptr = ptr.next;
            }
            Console.Write("NULL\n");
        }
    }
}

public class Program
{
    private const int MAXSIZE = 5;
    private static int front = -1, rear = -1;
    private static LinkedList<int> listaEnlazada = new LinkedList<int>();

    public static void Insertar()
    {
        int elemento;
        Console.Write("\nIngrese el elemento: ");
        
        if (!int.TryParse(Console.ReadLine(), out elemento))
        {
            Console.WriteLine("\nEntrada no válida.\n");
            return;
        }

        if (rear == MAXSIZE - 1)
        {
            Console.WriteLine("\nDESBORDAMIENTO (OVERFLOW)\n");
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        listaEnlazada.LastInsert(elemento);
        Console.WriteLine("\nElemento insertado correctamente.\n");
    }

    public static void Eliminar()
    {
        if (front == -1 || front > rear)
        {
            Console.WriteLine("\nSUBDESBORDAMIENTO (UNDERFLOW)\n");
            return;
        }
        int elemento = listaEnlazada.begin_delete();
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        Console.WriteLine($"\nElemento eliminado: {elemento}\n");
    }

    public static void Mostrar()
    {
        if (rear == -1 || front == -1 || front > rear)
        {
            Console.WriteLine("\nLa cola esta vacia.\n");
        }
        else
        {
            Console.WriteLine("\nElementos en la cola:\n");
            listaEnlazada.display();
        }
    }

    public static void Main(string[] args)
    {
        int opcion = 0;

        while (opcion != 4)
        {
            Console.WriteLine("\n************************* MENU PRINCIPAL ***************************\n");
            Console.WriteLine("======================================================================\n");
            Console.WriteLine("1. Insertar un elemento\n");
            Console.WriteLine("2. Eliminar un elemento\n");
            Console.WriteLine("3. Mostrar La cola\n");
            Console.WriteLine("4. Salir\n");
            Console.Write("Ingrese su opcion: ");
            
            int.TryParse(Console.ReadLine(), out opcion);

            switch (opcion)
            {
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
                    Console.WriteLine("\nSaliendo del programa...\n");
                    break;
                default:
                    Console.WriteLine("\nOpcion invalida. Intente nuevamente.\n");
                    break;
            }
        }
    }
}