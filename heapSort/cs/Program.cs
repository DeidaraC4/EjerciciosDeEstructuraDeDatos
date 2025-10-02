using System;

namespace heapsort
{
    public class Program
    {
        static void heapSort(int[] array)
        {
            int temp = 0;
            for(int i = 1; i < array.Length; i++){
                for(int j = array.Length - i; j > 0; j--)
                {
                    double flotante = (j - 1)/2;
                    flotante = Math.Round(flotante);
                    int entero = Convert.ToInt32(flotante);
                    if(array[j] > array[entero]){
                        temp = array[j];
                        array[j] = array[entero];
                        array[entero] = temp;
                    }
                }
                temp = array[0];
                array[0] = array[array.Length - i];
                array[array.Length - i] = temp;
            }
        }
        static void Main(string[] args)
        {
            int[] arr = {6, 1, 5, 60, 13, 2, 78, 41, 11, 14, 18, 38, 484, 23, 1};
            
            Console.WriteLine("Los elementos desordenados son: ");
            foreach(int ele in arr)
            {
                Console.Write(ele + " ");
            }Console.WriteLine();

            heapSort(arr);

            Console.WriteLine("Los elementos ordenados son: ");
            foreach(int ele in arr)
            {
                Console.Write(ele + " ");
            }Console.WriteLine();
        }
    }
}