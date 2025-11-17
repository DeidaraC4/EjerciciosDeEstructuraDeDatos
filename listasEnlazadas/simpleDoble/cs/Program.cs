using System;

namespace DoublyLinkedList
{
    class Node
    {
        public int data;
        public Node next;
        public Node prev;

        public Node(int dato)
        {
            data = dato;
            next = null;
            prev = null;
        }
    }

    class LinkedList
    {
        public Node head;

        public LinkedList()
        {
            head = null;
        }

        public void beginsert(int data)
        {
            Node ptr = new Node(data);
            if (head == null)
            {
                head = ptr;
            }
            else
            {
                ptr.next = head;
                head.prev = ptr;
                head = ptr;
            }
            Console.WriteLine("Nodo insertado al inicio.");
        }

        public void lastinsert(int data)
        {
            Node ptr = new Node(data);
            if (head == null)
            {
                ptr.next = head;
                head = ptr;
            }
            else
            {
                Node temp = head;
                while (temp.next != null)
                {
                    temp = temp.next;
                }
                temp.next = ptr;
                ptr.prev = temp;
            }
            Console.WriteLine("Nodo insertado al final.");
        }

        public void randominsert(int data, int loc)
        {
            Node ptr = new Node(data);
            Node temp = head;

            if (loc == 0)
            {
                ptr.next = head;
                if (head != null)
                {
                    head.prev = ptr;
                }
                head = ptr;
            }
            else
            {
                for (int i = 0; i < loc; i++)
                {
                    temp = temp.next;
                    if (temp == null)
                    {
                        Console.WriteLine("no se pudo alcanzar dicha locacion");
                        return;
                    }
                }
                ptr.next = temp.next;
                if (temp.next != null) temp.next.prev = ptr;
                temp.next = ptr;
                ptr.prev = temp;
            }
            Console.WriteLine("Nodo insertado en la posicion " + loc + ".");
        }

        public void begin_delete()
        {
            if (head == null)
            {
                Console.WriteLine("la lista esta vacia");
            }
            else if (head.next == null)
            {
                head = null;
            }
            else
            {
                head = head.next;
                head.prev = null;
                Console.WriteLine("Primer nodo eliminado.");
            }
        }

        public void last_delete()
        {
            Node temp = head;
            if (head == null)
            {
                Console.WriteLine("la lista esta vacia");
            }
            else if (head.next == null)
            {
                head = null;
                Console.WriteLine("Ultimo nodo eliminado (la lista ahora esta vacia).");
            }
            else
            {
                while (temp.next.next != null)
                {
                    temp = temp.next;
                }
                temp.next = null;
                Console.WriteLine("Ultimo nodo eliminado.");
            }
        }

        public void random_delete(int loc)
        {
            if (head == null)
            {
                Console.WriteLine("la lista esta vacia");
            }
            else
            {
                Node temp = head;
                Node temp2 = null;
                if (loc == 0)
                {
                    if (head.next == null)
                    {
                        head = null;
                        return;
                    }
                    head = head.next;
                    head.prev = null;
                }
                else
                {
                    for (int i = 0; i < loc; i++)
                    {
                        temp2 = temp;
                        temp = temp.next;
                        if (temp == null)
                        {
                            Console.WriteLine("eliminacion fuera de rango");
                            return;
                        }
                    }
                    temp2.next = temp.next;
                    if (temp.next != null)
                    {
                        temp.next.prev = temp2;
                    }
                }
                Console.WriteLine("Nodo en la posicion " + loc + " eliminado.");
            }
        }

        public void search(int ele)
        {
            Node temp = head;
            int loc = 0;
            bool found = false;
            if (head == null)
            {
                Console.WriteLine("La lista esta vacia");
            }
            else
            {
                while (temp != null)
                {
                    if (temp.data == ele)
                    {
                        found = true;
                        break;
                    }
                    temp = temp.next;
                    loc += 1;
                }
                if (found)
                {
                    Console.WriteLine("elemento " + ele + " encontrado en la posicion  " + loc);
                }
                else
                {
                    Console.WriteLine("Elemento " + ele + " NO encontrado en la lista.");
                }
            }
        }

        public void display()
        {
            Node ptr = head;
            if (head == null)
            {
                Console.WriteLine("Lista vacia");
            }
            else
            {
                string output = "";
                while (ptr != null)
                {
                    output += ptr.data + "<->";
                    ptr = ptr.next;
                }
                output += "NULL";
                Console.WriteLine(output);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            LinkedList lista = new LinkedList();
            int choice = 0;
            int ele = 0;
            int ele2 = 0;

            do
            {
                Console.WriteLine("\n\n*********Menu principal*********\n"
                     + "\nElige una opcion de la siguiente lista ...\n"
                     + "\n===============================================\n"
                     + "\n1. insertar al principio\n2. insertar al final\n3. insertar\n4. eliminar al principio"
                     + "\n5. eliminar el ultimo\n6. eliminar nodo despues de la ubicacion especificada\n7. buscar un elemento\n8. mostrar\n9. salir\n"
                     + "\nIngrese su opcion?\n");

                string input = Console.ReadLine();
                if (!int.TryParse(input, out choice))
                {
                    Console.WriteLine("Entrada invalida. Por favor ingrese un numero.");
                    continue;
                }

                switch (choice)
                {
                    case 1:
                        Console.WriteLine("Escribe un elemento a agregar");
                        ele = int.Parse(Console.ReadLine());
                        lista.beginsert(ele);
                        break;
                    case 2:
                        Console.WriteLine("Escribe un elemento a agregar");
                        ele = int.Parse(Console.ReadLine());
                        lista.lastinsert(ele);
                        break;
                    case 3:
                        Console.WriteLine("Escribe un elemento a agregar");
                        ele = int.Parse(Console.ReadLine());
                        Console.WriteLine("Escribe la posicion donde se va a agregar");
                        ele2 = int.Parse(Console.ReadLine());
                        lista.randominsert(ele, ele2);
                        break;
                    case 4:
                        lista.begin_delete();
                        break;
                    case 5:
                        lista.last_delete();
                        break;
                    case 6:
                        Console.WriteLine("Escribe la posicion del elemento a eliminar");
                        ele = int.Parse(Console.ReadLine());
                        lista.random_delete(ele);
                        break;
                    case 7:
                        Console.WriteLine("Escribe un elemento a buscar");
                        ele = int.Parse(Console.ReadLine());
                        lista.search(ele);
                        break;
                    case 8:
                        lista.display();
                        break;
                    case 9:
                        Console.WriteLine("saliendo del programa");
                        break;
                    default:
                        Console.WriteLine("Opcion invalida introduzca una opcion valida");
                        break;
                }
            } while (choice != 9);
        }
    }
}