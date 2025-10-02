public class Main{
    public static void heapSort(int[] array){
        int temp = 0;
        for(int i = 1; i < array.length; i++){
            for(int j = array.length - i; j > 0; j--){
                if(array[j] > array[Math.round((j-1)/2)]){
                    temp = array[j];
                    array[j] = array[Math.round((j-1)/2)];
                    array[Math.round((j-1)/2)] = temp;
                }
            }
            temp = array[0];
            array[0] = array[array.length - i];
            array[array.length - i] = temp;
        }
    }
    public static void main(String[] args){
        int[] arr = {6, 1, 5, 60, 13, 2, 78, 41, 11, 14, 18, 38, 484, 23, 1};

        System.out.println("el array desordenado es:");
        for(int ele : arr){
            System.out.print(ele + " ");
        } System.out.println();

        heapSort(arr);

        System.out.println("el array ordenado es:");
        for(int ele : arr){
            System.out.print(ele + " ");
        } System.out.println();
    }
}