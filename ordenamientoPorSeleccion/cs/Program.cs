using System;

namespace selection
{
    public class Program
    {
        static int[] arr = {45, 62, 41, 41, 34, 31, 87, 99, 86, 15};
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
            Console.WriteLine("El array desordenado es:");
            printArr(arr);

            for (int i = 0; i < arr.Length; i++)
            {
                int little = i;

                for (int j = i + 1; j < arr.Length; j++)
                {
                    if (arr[little] > arr[j])
                    {
                        little = j;
                    }
                }
                int temp = arr[i];
                arr[i] = arr[little];
                arr[little] = temp;
            }

            Console.WriteLine("El array ordenado es:");
            printArr(arr);
        }
    }
}