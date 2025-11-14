#include <iostream>
using namespace std;

#define MAXSIZE 5 // tamaño maximo de la cola
int queue[MAXSIZE]; //arreglo para almacenar los elementos de la cola

int front = -1, rear = -1; //la parte frontal(de donde salen los elementos) y la parte posterior o trasera(donde entran los elementos) se inicializa en -1

void insertar(){
    int elemento;
    cout << "\nIngrese el elemento: ";
    cin >> elemento;
    if(rear == MAXSIZE - 1){
        cout << "\nDESBORDAMIENTO (OVERFLOW)\n";
        return;
    }
    if(front == -1 && rear == -1){//primer elemento que se pone en la cola
        front = rear = 0;
    }else{
        rear++; //el trasero o parte posterior es el unico que aumenta cuando se añade un elemento
    }
    queue[rear] = elemento;
    cout << "\nElemento insertado correctamente.\n";
}

void eliminar(){
    if(front == -1 || front > rear){ //si la cola esta vacia o ya se eliminaron todos los elementos es un underflow
        cout << "\nSUBDESBORDAMIENTO (UNDERFLOW)\n";
        return;
    }
    int elemento = queue[front];
    if(front == rear){ //se reinicia la cola para que los elementos eliminados no desperdicien memoria (creo)
        front = rear = -1;
    } else{
        front++;
    }
    cout << "\nElemento eliminado: " << elemento << "\n";
}

void mostrar(){
    if(rear == -1 || front == -1 || front > rear){ // no se me ocurre un caso donde front sea mayor que rear
        cout << "\nLa cola esta vacia.\n";
    } else{
        cout << "\nElementos en la cola:\n";
        for(int i = front; i <= rear; i++){
            cout << queue[i] << "\n";
        }
    }
}

int main(){
    int opcion = 0;

    while(opcion != 4){
        cout << "\n************************* MENU PRINCIPAL ***************************\n";
        cout << "======================================================================\n";
        cout << "1. Insertar un elemento\n";
        cout << "2. Eliminar un elemento\n";
        cout << "3. Mostrar La cola\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            insertar();
            break;
        case 2:
            eliminar();
            break;
        case 3:
            mostrar();
            break;
        case 4:
            cout << "\nSaliendo del programa...\n";
            break;
        
        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n";
            break;
        }
    }
    return 0;
}