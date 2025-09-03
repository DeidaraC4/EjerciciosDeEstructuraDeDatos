#include<iostream>

using namespace std;

class Persona{
    public:
    virtual string dice() const = 0;
};

class Estudiante : public Persona{
    string name, faculty;
    public:
    Estudiante(string n, string f) : name(n), faculty(f){}
    string dice() const override{return "hola, quiero pedir unas pizzas a nombre de " + name + ". Si ya se que es muy tarde, pero me voy a quedar hasta la noche a terminar las practicas de estructura de datos... entreguelas en la facultad de " + faculty + "\n";}
};

int main(){
    Estudiante estudiante = Estudiante("Erick", "ingenieria");
    cout << estudiante.dice();
    return 0;
}