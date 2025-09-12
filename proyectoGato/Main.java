package proyectoGato;
import java.util.Scanner;


public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Boolean winner = false;
        Short player = 0;
        short fila, columna, turn;
        turn = 0;
        String mark;
        String[][] gato = {
            {"", "", ""},
            {"", "", ""},
            {"", "", ""}
        };

        System.out.println("Escriba una posicion del 0 al 2");
        while (winner == false) {
            if (player == 0) {
                System.out.println("Turno del jugador O: \n");
                mark = "O";
            } else{
                System.out.println("Turno del jugador X: \n");
                mark = "X";
            }
            
            do {
                System.out.println("Ingresar posicion en la fila: ");
                fila = Short.parseShort(input.nextLine());
                
                System.out.println("Ingresar posicion en la columna: ");
                columna = Short.parseShort(input.nextLine());
                
                if (gato[fila][columna] != ""){
                    System.out.println("Por favor elija un espacio desocupado: ");
                }
            } while (gato[fila][columna] != "");
            gato[fila][columna] = mark;

            if (turn >= 4){
                salir:
                for (int i = 0; i < gato.length; i++) {
                    for (int j = 0; j < gato.length; j++) {
                        if (j < 2){
                            if (gato[i][j] != gato[i][j+1] && gato[j][i] != gato[j+1][i]){
                                break;
                            } else if (j == 1 && gato[i][j] != ""){
                                System.out.println("El ganador es el jugador: " + mark);
                                System.out.println("print: " + i + " " + j);
                                winner = true;
                                break salir;
                            }
                        }
                    }
                }
                for (int j = 0; j < gato.length; j++) {
                    if (gato[j][j] == gato[j+1][j+1] && j == 1){
                        System.out.println("El ganador es el jugador: " + mark);
                        winner = true;
                        break;
                    } else{
                        break;
                    }
                }
            }


            if (player == 0){
                player = 1;
            } else{
                player = 0;
            }
            turn++;
            if (turn == 8){
                System.out.println("\n\nno hay ganadores");
                winner=true;
            }
        }
        input.close();
    }
}
