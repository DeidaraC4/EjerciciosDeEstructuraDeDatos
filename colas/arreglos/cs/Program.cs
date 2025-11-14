using System;

public class Program
{
    private const int MAXSIZE = 5;
    private static int[] queue = new int[MAXSIZE];
    private static int front = -1, rear = -1;

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
        queue[rear] = elemento;
        Console.WriteLine("\nElemento insertado correctamente.\n");
    }

    public static void Eliminar()
    {
        if (front == -1 || front > rear)
        {
            Console.WriteLine("\nSUBDESBORDAMIENTO (UNDERFLOW)\n");
            return;
        }
        int elemento = queue[front];
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
            for (int i = front; i <= rear; i++)
            {
                Console.WriteLine(queue[i]);
            }
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