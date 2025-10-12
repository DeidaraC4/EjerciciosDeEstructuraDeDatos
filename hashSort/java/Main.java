
public class Main {
    public static void main(String[] args){
        int[] arr = {4, 10, 9, 47, 90, 9, 3, 341, 551, 79, 8};
        System.out.println("Elementos desordenados");

        for(int ele : arr){
        System.out.print(ele + " ");
        }System.out.println("");

        for(int div = (arr.length - 1)/2; div >= 1; div/=2){
            int separation = div;
            for(int i = div; i < arr.length; i++){
                int reserve = arr[i];

                int j = i - separation;
                while(j >= 0 && reserve < arr[j]){
                    arr[j + separation] = arr[j];

                    j -= separation;
                }
                arr[j + separation] = reserve;
            }
        }

        System.out.println("Elementos ordenados");
        for(int ele : arr){
        System.out.print(ele + " ");
        }System.out.println("");
    }
}
