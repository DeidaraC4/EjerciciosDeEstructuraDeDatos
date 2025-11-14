#include <iostream>
#define MAXSIZE 100

using namespace std;

//declaracion de la estructura de nodo
struct node {
    int data; //almacena el valor numerico del nodo
    struct node *next; //puntero que apunta al siguiente nodo en la lista
};

struct node *head; // declaracion del head a null
struct node *fin; // declaracion de fin a null

void lastinsert(int item);
int last_delete();
void display();

int front = -1, rear = -1; //la parte frontal(de donde salen los elementos) y la parte posterior o trasera(donde entran los elementos) se inicializa en -1

//**************************************************************************************************************************************** */

int begin_delete();
void lastinsert(int item);
void display();

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
    lastinsert(elemento); //last insert, el primero que se pone es el primero que sale con begindelete
    cout << "\nElemento insertado correctamente.\n";
}

void eliminar(){
    if(front == -1 || front > rear){ //si la cola esta vacia o ya se eliminaron todos los elementos es un underflow
        cout << "\nSUBDESBORDAMIENTO (UNDERFLOW)\n";
        return;
    }
    int elemento = begin_delete(); // mostrar el primer elemento de la lista enlazada a ser eliminadom (cabeza)
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
        display();
    }
}

//******************************************************************************************************************************************** */
//ejemplo de uso de la pila
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
            cout << "\nSaliendo ..\n";
            break;
        
        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n";
            break;
        }
    }

    return 0;
}
//***************************************************************************************************************************************** */
//implementacion de las funcioes de linked list
void lastinsert(int item)
{
    struct node *ptr;
    
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = item;
    
    if(ptr == NULL) //verifica si hay memoria disponible
    { cout << "\nOVERFLOW";
    }
    else
    {
        //caso especial: lista vacia
        if(head == NULL)
        {
            ptr->next = NULL;
            fin = ptr;
            head = ptr;
        }else{
            fin->next = ptr;
            ptr->next = NULL;
            fin = ptr;
        }
    }
}

int begin_delete(){
    struct node *ptr;

    if(head == NULL){
        cout << "\nla lista esta vacia\n"; //jamas entrara aqui
    }else{
        ptr = head;
        int data = ptr->data;
        head = ptr->next;
        delete ptr;
        cout << "\nNodo eliminado desde el principio...\n";
        return data;
    }
}

void display()
{
    //puntero para recorrer la lista
    struct node *ptr;
    ptr = head; //comienza desde el principio

    //verifica si la lista esta vacia
    if(ptr == NULL){
        cout << "nada que imprimir"; // quiza nunca entre aqui
    }
    else
    {
        //imprime todos los elementos de la lista
        cout << "\nimprimiendo valores . . . . .\n";
        while(ptr != NULL){
            cout << ptr->data << "->"; //imprime el valor del nodo actual
            ptr = ptr->next;           //avanza al siguiente nodo
        }
        cout << "NULL";
    }
}