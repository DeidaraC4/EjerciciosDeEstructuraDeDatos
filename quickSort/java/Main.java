

public class Main {
    public static int getPivot(int[] array, int start, int end){
        int temp = 0;
        int i = start - 1;
        int pivot = array[end];

        for(int j = start; j <= end; j++){
            if(array[j] <= pivot){
                i++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        return i;
    }

    public static void quickSort(int[] array, int start, int end){
        if(end <= start){return;}

        int pivot = getPivot(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
    public static void main(String[] args){
        int[] arr = {78, 64, 91, 73, 40, 15, 91, 36, 47, 51, 67, 19, 34, 69, 2, 1, 36, 4, 49, 7, 25, 94, 53, 5, 2};
        System.out.println("Los numeros desordenados son: ");
        for(int ele : arr){
            System.out.print(ele + " ");
        }System.out.println("\nLos numeros ordenados son: ");
        quickSort(arr, 0, arr.length - 1);
        for(int ele : arr){
            System.out.print(ele + " ");
        }System.out.println();
    }
}


