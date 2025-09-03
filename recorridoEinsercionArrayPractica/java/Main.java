import java.util.Scanner;


public class Main {
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);

        int[] arr = {10, 20, 30, 40, 50, 60};
        
        System.out.println("Los elementos del array son: ");
        for (int i : arr){
            System.out.print(" " + i);
        }
        System.out.println();
        System.out.println("Ingrese un numero: ");
        int num = entrada.nextInt();
        System.out.println("Ingrese una posicion (0-5): ");
        int position = entrada.nextInt();

        for (int i = arr.length - 1; i>position; i--){
            arr[i] = arr[i - 1];
        }
        arr[position] = num;
        System.out.println("El arreglo modificado tiene los siguientes elementos: ");

        for (int i : arr){
            System.out.print(" " + i);
        }
        System.out.println();
    }
}