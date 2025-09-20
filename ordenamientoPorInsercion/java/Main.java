public class Main{
    static int[] arr = {29, 84, 56, 2, 76, 37, 39, 2};
    private static void printArr(int[] arr){
        for(int ele : arr){
            System.out.print(ele + " ");
        }
        System.out.println("\n");
    }
    
    public static void main(String[] args){
        System.out.println("El array desordenado es:");
        printArr(arr);
        for(int i = 1; i < arr.length; i++){
            int reserva = arr[i];

            int j = i - 1;
            while(j >= 0 && reserva < arr[j]){
                arr[j + 1] = arr[j];

                j -= 1;
            }
            arr[j + 1] = reserva;
        }
        System.out.println("El array ordenado es:");
        printArr(arr);
    }
}