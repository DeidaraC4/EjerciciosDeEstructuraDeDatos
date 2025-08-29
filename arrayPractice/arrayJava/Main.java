import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        //array tradicional (estatico en cantidad de elementos e impractico en la modificacion de elementos masivamente)
        int[] array = {1, 2, 3, 4};
        System.out.println("el primer numero de arreglo es " + array[0]);

        for (int i : array) {
            System.out.println("elemento del array: " + i);
        }
        
        array[0] = 25;

        for (int i : array) {
        System.out.println("elemento del array modificado: " + i);
        }

        //Array dinamico en la cantidad de elementos
        ArrayList<String> array2 = new ArrayList<>();

        array2.add("rojo");
        array2.add("amarillo");

        for (String i : array2) {
            System.out.println("elemento del array2: " + i);
        }

        array2.clear();

        int sizeOfArray2 = array2.size();
        System.out.println("ahora la cantidad de elementos que hay en el array es: " + sizeOfArray2);
    }
}