#include <iostream>
#define MAX_SIZE 100 // tamaño maximo de la pila

using namespace std;

int stack[MAX_SIZE]; //arreglo para almacenar los elementos de la pila
int top = -1; //indice del elemento superior de la pila

//funcion para agregar un elemento a la pila
void push(int item){
    if(top == MAX_SIZE - 1){ //verifica si la pila esta llena
        cout << "stack overflow" << endl; //errir si hay desbordamiento
        return;
    }
    stack[++top] = item; //incrementa el indice y agrega el elemento
}
//funcion para eliminar y retornar el elemento superior de la pila
int pop(){
    if (top == -1){ //verifica si la pila esta vacia
        cout << "Stack Underflow" << endl;
    }
    return stack[top--];//retorna el elemento superior y decrementa el indice
}
//funcion para ver el elemento superior sin eliminarlo
int peek(){
    if (top == -1){// verifica si la pila esta vacia
        cout << "Pila vacia" << endl;
        return -1; //retorna -1 para indicar que la pila esta vacia
    }
    return stack[top]; //retorna el elemento superior sin modificar el indice
}
// funcion para verificar si la pila esta vacia
bool isEmpty() {//verifica si el indice superior es -1
    return top == -1; //retorna true si esta vacia, false en caso contrario
}
//funcion para verificar si la pila esta llena
bool isFull(){//verifica si el indice superior es igual al tamano maximo menos uno
    return top == MAX_SIZE - 1; //retorna true si esta llena, false en caso contrario
}
//ejemplo de uso de la pila
int main(){
    push(10);//agrega elementos a la pila
    push(20);//agrega otro elemento
    push(30);//agrega otro elemento

    cout << "elemento superior: " << peek() << endl; //muestra el elemento superior
    cout << "extrae elemento: " << pop() << endl; //elimina y muestra el elemento superior
    cout << "elemento superior: " << peek() << endl; //muestra el nuevo elemento superior

    return 0;
}