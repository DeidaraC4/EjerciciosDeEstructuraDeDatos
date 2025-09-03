package abstractTypesPractice.abstractJava;

public class Main {
    public static void main(String[] args){
        abstract class Persona{
            abstract void dice();
        }

        class Estudiante extends Persona{
            @Override
            void dice() {
                System.out.println("Odio mi vida");
            }
        }
        Persona Leonardo = new Estudiante();
        Leonardo.dice();
    }
}
