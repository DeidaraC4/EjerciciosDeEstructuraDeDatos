using System;
using System.Collections;
using System.Linq.Expressions;
using System.Runtime.InteropServices;
using Microsoft.VisualBasic;

namespace bucketSort
{
    public class Program
    {
        static void Main(string[] args)
        {
            float[] arr = { 0.93f, 0.4f, 0.50f, 0.34f, 0.94f, 0.90f, 0.94f, 0.992f, 0.42f, 0.34f, 0.42f, 0.33f, 0.25f, 0.2f, 0.04f, 0.19f, 0.52f, 0.07f, 0.32f };
            Console.WriteLine("Los elementos desordenados son:");
            foreach(float ele in arr)
            {
                Console.Write(ele + " ");
            } Console.WriteLine();

            List<List<float>> bucket = new List<List<float>>();
            for (int i = 0; i < 10; i++)
            {
                bucket.Add(new List<float>());
            }

            foreach (float ele in arr)
            {
                bucket[(int)ele * 10].Add(ele);
            }

            int index = 0;
            foreach (List<float> list in bucket)
            {
                list.Sort();
                foreach (float ele in list)
                {
                    arr[index++] = ele;
                }
            }

            Console.WriteLine("Los elementos ordenados son:");
            foreach(float ele in arr)
            {
                Console.Write(ele + " ");
            } Console.WriteLine();
        }
    }
}