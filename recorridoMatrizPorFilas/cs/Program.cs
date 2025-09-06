using System;

namespace matriz
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[9];
            int[,] twoDimArr = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            Console.WriteLine("Los elementos del array bidimensional son: ");

            int k = 0;
            for (int i = 0; i < twoDimArr.GetLength(0); i++)
            {
                for (int j = 0; j < twoDimArr.GetLength(1); j++)
                {
                    arr[k++] = twoDimArr[i, j];
                    Console.Write(twoDimArr[i, j]);
                }
                Console.WriteLine();
            }

            Console.WriteLine("Los elementos del array unidimensional son:");
            foreach (int i in arr)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }
    }
}