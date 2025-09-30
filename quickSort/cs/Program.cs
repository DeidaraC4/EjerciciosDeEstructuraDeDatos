using System;
using System.Globalization;
using System.Linq.Expressions;

namespace quickSortProgram
{
    public class Program
    {
        static int getPivot(int[] array, int start, int end)
        {
            int pivot = array[end];
            int temp;
            int i = start - 1;

            for (int j = start; j <= end; j++)
            {
                if (array[j] <= pivot)
                {
                    i++;
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
            return i;
        }
        static void quickSort(int[] array, int start, int end)
        {
            if (end <= start) { return; }

            int pivot = getPivot(array, start, end);
            quickSort(array, start, pivot - 1);
            quickSort(array, pivot + 1, end);
        }
        static void Main(string[] args)
        {
            int[] arr = { 78, 64, 91, 73, 40, 15, 91, 36, 47, 51, 67, 19, 34, 69, 2, 1, 36, 4, 49, 7, 25, 94, 53, 5, 2 };
            Console.WriteLine("Los elementos desordenados son: ");

            foreach (int ele in arr)
            {
                Console.Write(ele + " ");
            }
            Console.WriteLine("\n Los elementos ordenados son: ");

            quickSort(arr, 0, arr.Length - 1);

            foreach (int ele in arr)
            {
                Console.Write(ele + " ");
            }
            Console.WriteLine();
        }
    }
}