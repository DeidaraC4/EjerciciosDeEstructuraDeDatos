using System;
using System.Globalization;

namespace insercion
{
    public class Program
    {
        static int[] arr = {29, 84, 56, 2, 76, 37, 39, 2};
        static void printArr(int[] arr)
        {
            foreach (int ele in arr)
            {
                Console.Write(ele + " ");
            }
            Console.WriteLine();
        }
        static void Main(string[] args)
        {
            Console.WriteLine("El array desordenado es: ");
            printArr(arr);
            for (int i = 1; i < arr.Length; i++)
            {
                int reserva = arr[i];

                int j = i - 1;
                while (j >= 0 && reserva < arr[j])
                {
                    arr[j + 1] = arr[j];
                    j -= 1;
                }
                arr[j + 1] = reserva;
            }
            Console.WriteLine("El array ordenado es: ");
            printArr(arr);
        }
    }
}