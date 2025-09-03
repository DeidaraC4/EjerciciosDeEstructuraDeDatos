// See https://aka.ms/new-console-template for more information

using System;

namespace arrayProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] array = { "blue", "yellow", "red" };
            Console.WriteLine("el color del indice 0 es: " + array[0]);

            array[0] = "Gold";

            foreach (string i in array)
            {
                Console.WriteLine("el color del array modificado es: " + i);
            }

            Array.Sort(array);

            foreach (string i in array)
            {
                Console.WriteLine("Los colores ordenados alfabeticamente se ven asi: " + i);
            }
        }
    }
}
