public class Main{
    public static void main(String[] args){
        int[] arr = {64, 39, 82, 37, 49, 21, 18, 54, 21, 34, 87, 21, 32, 41, 23, 23, 67, 98, 43, 56};
        int bubble = 0;
        
        
        System.out.println("los elementos del array desordenado son:");
        for (int ele : arr){
            System.out.print(ele + " ");
        }
        System.out.println();

        for (int i = 0; i < arr.length - 1; i++){
            for (int j = 0; j < arr.length - 1 - i; j++){
                if (arr[j] > arr[j+1]){
                    bubble = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = bubble;
                }
            }
        }

        System.out.println("los elementos del array ordenado son:");
        for (int ele : arr){
            System.out.print(ele + " ");
        }
        System.out.println();
    }
}