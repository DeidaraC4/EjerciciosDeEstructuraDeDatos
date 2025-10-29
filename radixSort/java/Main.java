import java.lang.Math;

public class Main{
    
    public static void printArray(int[] arr) {
        for (int ele : arr) {
            System.out.print(ele + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = {938, 4, 102, 30, 5, 2, 4928, 701, 230, 71, 92, 474, 91, 2};

        System.out.print("desordenados: ");
        printArray(arr);

        // Encontrar el maximo
        int max = arr[0];
        for (int ele : arr) {
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
            for (int i = 1; i < arr.length; i++) {
                int reserva = arr[i];
                int j = i - 1;

                int exp = (int)Math.pow(10, k);
                while (j >= 0 && (reserva / exp) % 10 < (arr[j] / exp) % 10) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = reserva;
            }
        }

        System.out.print("ordenados: ");
        printArray(arr);
    }
}