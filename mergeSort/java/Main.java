public class Main{
    public static void merge(int[] array, int left, int mid, int right){
        int a1 = mid - left + 1; //a1 = tamaño del arreglo izquierdo a2 = del derecho
        int a2 = right - mid;

        int[] L = new int[15]; //arreglo de 15 enteros
        int[] R = new int[15];

        for(int j = 0; j < a1; j++){ //llenar los elementos
            L[j] = array[left + j];
        }

        for(int k = 0; k < a2; k++){
            R[k] = array[mid + 1 + k];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while(i < a1 & j < a2){
            if(L[i] < R[j]){
                array[k] = L[i];
                i++;
                k++;
            } else{
                array[k] = R[j];
                j++;
                k++;
            }
        }

        while(i < a1){
            array[k] = L[i];
            i++;
            k++;
        }

        while(j < a2){
            array[k] = R[j];
            j++;
            k++;
        }
    }
    public static void mergeSort(int[] array, int left, int right){
        if(left < right){
            int mid = Math.round((right - left)/2) + left;

            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }
    public static void main(String[] args){
        int[] arr = {34, 1, 48, 71, 29, 12, 303, 81, 8, 315, 3, 4, 32, 52, 53};

        System.out.println("Los elementos desordenados son: ");
        for(int ele : arr){
            System.out.print(ele + " ");
        }System.out.println();

        mergeSort(arr, 0, arr.length - 1);

        System.out.println("Los elementos ordenados son: ");
        for(int ele : arr){
            System.out.print(ele + " ");
        }System.out.println();
    }
}