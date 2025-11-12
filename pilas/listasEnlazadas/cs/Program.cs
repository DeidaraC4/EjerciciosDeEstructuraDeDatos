using System;

// Definición de la clase Node (Nodo)
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

// Definición de la clase LinkedList (Lista Enlazada)
public class LinkedList<T>
{
    private Node<T> head;
    private Node<T> fin;

    public LinkedList()
    {
        head = null;
        fin = null; //para no tener que estar recorriendo hasta lo ultimo y conectarlo directamente con el inicio
    }

    public void LastInsert(T data)
    {
        Node<T> ptr = new Node<T>(data);

        if (head == null)
        {
            ptr.next = head; // head es null, así que ptr.next es null
            head = ptr;
            fin = ptr;
        }
        else
        {
            fin.next = ptr;
            fin = ptr;
        }
    }

    public T LastDelete()
    {
        Node<T> temp = head;
        if (head == null)
        {
            Console.WriteLine("la lista esta vacia"); //nunca entraria
        }
        else if (head.next == head) // Lógica idéntica a la de Java
        {
            T numDeleted = fin.data;
            head = null;
            fin = null;
            return numDeleted;
        }
        else
        {
            T numDeleted = fin.data;
            // Manejo especial si hay solo un elemento (temp.next es null)
            if (temp.next == null) 
            {
                head = null;
                fin = null;
                return numDeleted;
            }
            
            while (temp.next.next != null) //no se si funcionara (lógica idéntica)
            {
                temp = temp.next;
            }
            fin = temp;
            fin.next = null; // Nota: Corregí un bug de tu lógica original (faltaba esto)
                             // Si quieres el bug original, comenta la línea de arriba y descomenta la de abajo
            // fin = temp; // Esta es tu lógica original sin romper el enlace
            return numDeleted;
        }
        return default(T); // para que no se este quejando c#
    }

    public T Display()
    {
        if (fin == null)
        {
            return default(T); // Maneja el caso de pila vacía
        }
        return fin.data;
    }
}

// Clase principal que implementa la Pila (Stack)
public class Program
{
    private const int MAX_SIZE = 100;
    private static int top = -1;
    private static LinkedList<int> lList = new LinkedList<int>();

    public static void Push(int item)
    {
        if (top == MAX_SIZE - 1)
        {
            Console.WriteLine("stack overflow");
            return;
        }
        top += 1;
        lList.LastInsert(item);
    }

    public static int Pop()
    {
        if (top == -1)
        {
            Console.WriteLine("Stack Underflow");
            return -1; // Devuelve -1 para concordar con peek()
        }
        top -= 1;
        // El tipo de retorno es int, pero LastDelete devuelve T (int).
        // Si LastDelete devuelve default(T) (que es 0 para int), se devolverá 0.
        return lList.LastDelete(); 
    }

    public static int Peek()
    {
        if (top == -1)
        {
            Console.WriteLine("Pila vacia");
            return -1;
        }
        return lList.Display();
    }

    public static bool IsEmpty()
    {
        return top == -1;
    }

    public static bool IsFull()
    {
        return top == MAX_SIZE - 1;
    }

    // Método Main para ejecutar el programa
    public static void Main(string[] args)
    {
        Push(10);
        Push(20);
        Push(30);

        Console.WriteLine("elemento superior: " + Peek());
        Console.WriteLine("extrae elemento: " + Pop());
        Console.WriteLine("elemento superior: " + Peek());
    }
}