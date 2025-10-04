using System;

namespace mergeProgram
{
    public class Program
    {
        static void merge(int[] array, int left, int mid, int right)
        {
            int a1 = mid - left + 1;
            int a2 = right - mid;

            int[] L = new int[a1];
            int[] R = new int[a2];

            for(int c1 = 0; c1 < a1; c1++)
            {
                L[c1] = array[left + c1];
            }

            for(int c2 = 0; c2 < a2; c2++)
            {
                R[c2] = array[mid + c2 + 1];
            }

            int i = 0;
            int j = 0;
            int k = left;

            while(i < a1 && j < a2)
            {
                if(L[i] < R[j])
                {
                    array[k] = L[i];
                    i++;
                    k++;
                }else
                {
                    array[k] = R[j];
                    j++;
                    k++;
                }
            }

            while(i < a1)
            {
                array[k] = L[i];
                i++;
                k++;
            }

            while(j < a2)
            {
                array[k] = R[j];
                j++;
                k++;
            }
        }
        static void mergeSort(int[] array, int left, int right)
        {
            if(left < right)
            {
                int mid = (right + left)/2;

                mergeSort(array, left, mid);
                mergeSort(array, mid + 1, right);
                merge(array, left, mid, right);
            }
        }
        static void Main(string[] args)
        {
            int[] arr = {34, 1, 48, 71, 29, 12, 303, 81, 8, 315, 3, 4, 32, 52, 53};
            Console.WriteLine("Los elementos desordenados son: ");
            foreach(int ele in arr)
            {
            Console.Write(ele + " ");
            }Console.WriteLine();

            mergeSort(arr, 0, arr.Length - 1);

            Console.WriteLine("Los elementos ordenados son: ");
            foreach(int ele in arr)
            {
            Console.Write(ele + " ");
            }Console.WriteLine();
        }
    }
}