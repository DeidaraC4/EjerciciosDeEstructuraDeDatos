public class Main{
    static int[] arr = {45, 62, 41, 41, 34, 31, 87, 99, 86, 15};
    static void printArr(int[] arr){
        for(int ele : arr){
            System.out.print(ele + " ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        System.out.println("El array desordenado es:");
        printArr(arr);

        for(int i = 0; i < arr.length; i++){
            int little = i;

            for(int j = i + 1; j < arr.length; j++){
                if(arr[little] > arr[j]){
                    little = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[little];
            arr[little] = temp;
        }
        
        System.out.println("El array ordenado es:");
        printArr(arr);
    }
}