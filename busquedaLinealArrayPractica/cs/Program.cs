// See https://aka.ms/new-console-template for more information
using System;

namespace busqueda
{
    class Program
    {
        static void Main(string[] args)
        {
            int counter = 0;
            int[] arr = { 1, 2, 3, 4, 5 };
            Console.WriteLine("Ingrese un numero para verificar su disponibilidad: ");
            string numS = Console.ReadLine();
            int num = int.Parse(numS);

            foreach (var i in arr)
            {
                if (i == num)
                {
                    Console.WriteLine("Existe");
                    break;
                } else if (counter == arr.Length - 1) {
                    Console.WriteLine("No existe");
                }
                counter += 1;
            }
        }
    }
}
