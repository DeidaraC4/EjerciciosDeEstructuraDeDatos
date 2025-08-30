// See https://aka.ms/new-console-template for more information

using System;

abstract class Persona
{
    public abstract string dice();
}

class Estudiante : Persona 
{
    private string edad, nombre;
    public Estudiante(string a, string n){edad = a; nombre = n; }
    public override string dice() {return "A nadie le importa pero me llamo " + nombre + " y tengo " + edad + " pero si te acercas a mi, pedire una orden de restriccion para ti";}
}

namespace abstractType
{
    class Program
    {
        static void Main(string[] args)
        {
            Estudiante estudiante = new Estudiante("19", "Erick");
            Console.WriteLine(estudiante.dice());
        }
    }
}