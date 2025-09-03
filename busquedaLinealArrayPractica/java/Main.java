import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int counter = 0;
        int[] arr = {1, 2, 3, 4, 5};
        System.out.println("Ingrese un numero para conocer su disponibilidad: ");
        int num = input.nextInt();
        
        for (int i : arr){
            if (i == num){
                System.out.println("existe");
                break;
            }else if (counter == arr.length - 1){
                System.out.println("no existe");
                break;
            }
            counter += 1;
        }
    }
}