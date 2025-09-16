using System;

namespace burbuja
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int[] arr = {64, 39, 82, 37, 49, 21, 18, 54, 21, 34, 87, 21, 32, 41, 23, 23, 67, 98, 43, 56};
            int bubble = 0;
        
        
            Console.WriteLine("los elementos del array desordenado son:");
            foreach (int ele in arr) {
                Console.Write(ele + " ");
            }
            Console.WriteLine();

            for (int i = 0; i < arr.Length - 1; i++){
                for (int j = 0; j < arr.Length - 1 - i; j++){
                    if (arr[j] > arr[j+1]){
                       bubble = arr[j+1];
                       arr[j+1] = arr[j];
                        arr[j] = bubble;
                    }
                }
            }

            Console.WriteLine("los elementos del array ordenado son:");
            foreach (int ele in arr) {
                Console.Write(ele + " ");
            }
            Console.WriteLine();
        }
    }
}
