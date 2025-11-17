#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int dato) {
        data = dato;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node *head;

    LinkedList() {
        head = nullptr;
    }

    void beginsert(int data) {
        Node *ptr = new Node(data);
        if (head == nullptr) {
            head = ptr;
        } else {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        cout << "Nodo insertado al inicio." << endl;
    }

    void lastinsert(int data) {
        Node *ptr = new Node(data);
        if (head == nullptr) {
            ptr->next = head;
            head = ptr;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
        }
        cout << "Nodo insertado al final." << endl;
    }

    void randominsert(int data, int loc) {
        Node *ptr = new Node(data);
        Node *temp = head;

        if(loc == 0){
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
        }else{
            for (int i = 0; i < loc; i++) {
                temp = temp->next;
                if (temp == nullptr) {
                    cout << "no se pudo alcanzar dicha locacion" << endl;
                    delete ptr;
                    return;
                }
            }
            ptr->next = temp->next;
            if(temp->next != nullptr) temp->next->prev = ptr;
            temp->next = ptr;
            ptr->prev = temp;
        }
        cout << "Nodo insertado en la posicion " << loc << "." << endl;
    }

    void begin_delete() {
        if (head == nullptr) {
            cout << "la lista esta vacia" << endl;
        } else if(head->next == nullptr){
            delete head;
            head = nullptr;
        }else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            cout << "Primer nodo eliminado." << endl;
            delete temp;
        }
    }

    void last_delete() {
        Node *temp = head;
        if (head == nullptr) {
            cout << "la lista esta vacia" << endl;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Ultimo nodo eliminado (la lista ahora esta vacia)." << endl;
        } else {
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            cout << "Ultimo nodo eliminado." << endl;
        }
    }

    void random_delete(int loc) {
        if (head == nullptr) {
            cout << "la lista esta vacia" << endl;
        } else {
            Node *temp = head;
            Node *temp2;
            if(loc == 0){
                if(head->next == nullptr) {delete head; head = nullptr; return;}
                head = head->next;
                head->prev = nullptr;
                delete temp;
                temp = nullptr;
            }else{
                for (int i = 0; i < loc; i++) {
                    temp2 = temp;
                    temp = temp->next;
                    if (temp == nullptr) {
                        cout << "eliminacion fuera de rango" << endl;
                        return;
                    }
                }
                temp2->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = temp2;
                }
                delete temp;
                temp = nullptr;
            }
            cout << "Nodo en la posicion " << loc << " eliminado." << endl;
        }
    }

    void search(int ele) {
        Node *temp = head;
        int loc = 0;
        bool found = false;
        if (head == nullptr) {
            cout << "La lista esta vacia" << endl;
        } else {
            while (temp != nullptr) {
                if (temp->data == ele) {
                    found = true;
                    break;
                }
                temp = temp->next;
                loc += 1;
            }
            if (found) {
                cout << "elemento " << ele << " encontrado en la posicion  " << loc << endl;
            } else {
                cout << "Elemento " << ele << " NO encontrado en la lista." << endl;
            }
        }
    }

    void display() {
        Node *ptr = head;
        if (head == nullptr) {
            cout << "Lista vacia" << endl;
        } else {
            string output = "";
            while (ptr != nullptr) {
                output += to_string(ptr->data) + "<->";
                ptr = ptr->next;
            }
            output += "NULL";
            cout << output << endl;
        }
    }
};

int main() {
    LinkedList lista;
    int choice = 0;
    int ele = 0;
    int ele2 = 0;

    do {
        cout << "\n\n*********Menu principal*********\n"
             << "\nElige una opcion de la siguiente lista ...\n"
             << "\n===============================================\n"
             << "\n1. insertar al principio\n2. insertar al final\n3. insertar\n4. eliminar al principio"
             << "\n5. eliminar el ultimo\n6. eliminar nodo despues de la ubicacion especificada\n7. buscar un elemento\n8. mostrar\n9. salir\n"
             << "\nIngrese su opcion?\n";
        
        while(!(cin >> choice)) {
            cout << "Entrada invalida. Por favor ingrese un numero." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (choice) {
            case 1:
                cout << "Escribe un elemento a agregar" << endl;
                cin >> ele;
                lista.beginsert(ele);
                break;
            case 2:
                cout << "Escribe un elemento a agregar" << endl;
                cin >> ele;
                lista.lastinsert(ele);
                break;
            case 3:
                cout << "Escribe un elemento a agregar" << endl;
                cin >> ele;
                cout << "Escribe la posicion donde se va a agregar" << endl;
                cin >> ele2;
                lista.randominsert(ele, ele2);
                break;
            case 4:
                lista.begin_delete();
                break;
            case 5:
                lista.last_delete();
                break;
            case 6:
                cout << "Escribe la posicion del elemento a eliminar" << endl;
                cin >> ele;
                lista.random_delete(ele);
                break;
            case 7:
                cout << "Escribe un elemento a buscar" << endl;
                cin >> ele;
                lista.search(ele);
                break;
            case 8:
                lista.display();
                break;
            case 9:
                cout << "saliendo del programa" << endl;
                break;
            default:
                cout << "Opcion invalida introduzca una opcion valida" << endl;
                break;
        }
    } while (choice != 9);

    return 0;
}