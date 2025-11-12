#include <iostream>
#define MAX_SIZE 100

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
int display();

int top = -1; 

//**************************************************************************************************************************************** */

//funcion para agregar un elemento a la pila
void push(int item){
    if(top == MAX_SIZE - 1){ 
        cout << "stack overflow" << endl; 
        return;
    }
    top += 1;
    lastinsert(item); 
}
//funcion para eliminar y retornar el elemento superior de la pila
int pop(){
    if (top == -1){ 
        cout << "Stack Underflow" << endl;
    }
    top -= 1;
    return last_delete();
}
//funcion para ver el elemento superior sin eliminarlo
int peek(){
    if (top == -1){
        cout << "Pila vacia" << endl;
        return -1; 
    }
    return display(); 
}
// funcion para verificar si la pila esta vacia
bool isEmpty() {
    return top == -1; 
}
//funcion para verificar si la pila esta llena
bool isFull(){
    return top == MAX_SIZE - 1; //retorna true si esta llena, false en caso contrario
}

//******************************************************************************************************************************************** */
//ejemplo de uso de la pila
int main(){
    push(10);
    push(20);
    push(30);

    cout << "elemento superior: " << peek() << endl; //muestra el elemento superior
    cout << "extrae elemento: " << pop() << endl; //elimina y muestra el elemento superior
    cout << "elemento superior: " << peek() << endl; //muestra el nuevo elemento superior

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

int last_delete(){
    struct node *ptr, *ptr1;

    //verifica si la lista esta vacia
    if(head == NULL)
    {
        cout << "\nUNDERFLOW";
    }
    //caso especial: solo hay un nodo
    else if (head->next == NULL){
        int numDeleted = ptr->data;
        delete head;
        delete fin;
        fin = NULL;
        head = NULL;
        return numDeleted;
    }
    //caso general: mas de un nodo
    else{
        ptr = head;
        // recorre la lista hasta el ultimo nodo
        // ptr1 mantiene el penultimo nodo
        while(ptr->next != NULL){
            ptr1 = ptr;         //guarda el nodo actual
            ptr = ptr->next;    //avanza al siguiente
        }
        int numDeleted = ptr->data;
        ptr1->next = NULL;
        fin = ptr1;
        delete ptr;
        return numDeleted;
    }
}

int display()
{
    // cout << "El ultimo nodo en la pila es: " << fin << endl;
    return fin->data;
}