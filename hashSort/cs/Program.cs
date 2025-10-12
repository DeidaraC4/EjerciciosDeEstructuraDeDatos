using System;
using System.ComponentModel.DataAnnotations;

namespace hashSort
{
    public class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 4, 10, 9, 47, 90, 9, 3, 341, 551, 79, 8 };
            Console.WriteLine("elementos desordenados");

            foreach (int ele in arr)
            {
                Console.Write(ele + " ");
            } Console.WriteLine();

            for (int div = (arr.Length - 1)/2; div >= 1; div /= 2)
            {
                int separation = div;
                for(int i = div; i < arr.Length; i++)
                {
                    int reserve = arr[i];

                    int j = i - separation;
                    while (j >= 0 && reserve < arr[j])
                    {
                        arr[j + separation] = arr[j];

                        j -= separation;
                    }
                    arr[j + separation] = reserve;
                }
            }

            Console.WriteLine("elementos ordenados");
            foreach(int ele in arr)
            {
                Console.Write(ele + " ");
            } Console.WriteLine();
        }
    }
}