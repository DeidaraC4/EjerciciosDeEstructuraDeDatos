using System;


namespace arrays
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 10, 20, 30, 40, 50 };
            Console.WriteLine("Los elementos del array son");
            foreach (var i in arr)
            {
                Console.Write(" " + i);
            }
            Console.WriteLine(" ");

            Console.WriteLine("Escribe un nuevo elemento para el array: ");
            string numS = Console.ReadLine();
            Console.WriteLine("Escribe la posicion del nuevo elemento del 0 al 5: ");
            string positionS = Console.ReadLine();

            int num = int.Parse(numS);
            int position = int.Parse(positionS);
            
            for (int i = arr.Length - 1; i > position; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[position] = num;

            Console.WriteLine("Los elementos de array modificado son: ");

            foreach (var i in arr)
            {
                Console.WriteLine(" " + i);
            }
            Console.WriteLine();
        }
    }
}