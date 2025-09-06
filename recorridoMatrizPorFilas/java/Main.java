

public class Main {
    public static void main(String[] args){
        int k = 0;
        int[] arr = new int[9];
        int[][] twoDimArr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        System.out.println("los elementos del array bidimensional son:");
        for (int[] row : twoDimArr){
            for (int ele : row){
                System.out.print(ele);
                arr[k++] = ele;
            }
            System.out.println();
        }

        System.out.println("los elementos de array unidimensional son:");
        for(int ele : arr){
            System.out.print(ele);
        }
        System.out.println();
    }
}
