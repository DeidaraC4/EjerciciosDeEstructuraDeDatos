import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
public class Main {
    public static void bucketSort(float[] arr) {
        if (arr.length == 0) {
            return;
        }

        List<List<Float>> buckets = new ArrayList<>(10); //la clase lista tiene las funciones esenciales de una lista dinamica, mientras que el arraylist es una implementacion en forma de array
        for (int i = 0; i < 10; i++) {
            buckets.add(new ArrayList<>());
        }

        for (float v : arr) {
            buckets.get((int)v*10).add(v);
        }

        for (List<Float> bucket : buckets) {
            Collections.sort(bucket);
        }

        int index = 0;
        for (List<Float> bucket : buckets) {
            for (float v : bucket) {
                arr[index++] = v;
            }
        }
    }
    public static void main(String[] args){
        float[] arr = {0.93f, 0.4f, 0.50f, 0.34f, 0.94f, 0.90f, 0.94f, 0.992f, 0.42f, 0.34f, 0.42f, 0.33f, 0.25f, 0.2f, 0.04f, 0.19f, 0.52f, 0.07f, 0.32f};
        System.out.println("Elementos desordenados");
        for(float ele : arr){
            System.out.print(ele + " ");
        } System.out.println();

        bucketSort(arr);

        System.out.println("Elementos ordenados");
        for(float ele : arr){
            System.out.print(ele + " ");
        } System.out.println();
    }
}
