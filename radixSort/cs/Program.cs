using System;

class Program {
    
    static void PrintArray(int[] arr) {
        foreach (int ele in arr) {
            Console.Write(ele + " ");
        }
        Console.WriteLine();
    }

    static void Main(string[] args) {
        int[] arr = {938, 4, 102, 30, 5, 2, 4928, 701, 230, 71, 92, 474, 91, 2};

        Console.Write("desordenados: ");
        PrintArray(arr);

        int max = arr[0];
        foreach (int ele in arr) {
            if (max < ele) {
                max = ele;
            }
        }

        int cont = 1;
        while (1 < max) {
            max /= 10;
            cont++;
        }

        for (int k = 0; k < cont; k++) {
            for (int i = 1; i < arr.Length; i++) {
                int reserva = arr[i];
                int j = i - 1;

                int power_of_10 = (int)Math.Pow(10, k);
                while (j >= 0 && (reserva / power_of_10) % 10 < (arr[j] / power_of_10) % 10) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = reserva;
            }
        }

        Console.Write("ordenados: ");
        PrintArray(arr);
    }
}