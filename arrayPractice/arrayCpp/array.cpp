#include<iostream>
#include<vector>

using namespace std;

int main(){
    int array[] = {1, 2, 3};
    cout << "El elemento 0 del array es: " << array[0] << "\n";

    for (int i : array){
        cout << "Elemento del array: " << i << "\n";
    }

    array[0] = 25;

    for (int i : array){
        cout << "Elemento del array modificado: " << i << "\n";
    }

    vector<string> array2 = {"red", "blue", "yellow"};

    for (string i : array2){
        cout << "Elemento del array dinamico (vector) es: " << i << "\n";
    }

    array2.push_back("newColor");

    for (string i : array2){
        cout << "Elemento modificado del vector es: " << i << "\n";
    }

    int size = sizeof(array2);

    cout << "El tamaño en bytes total de los elementos guardados del array nprmal es: " << size << "\n";

    int realSize = sizeof(array) / sizeof(array[1]);

    cout << "La cantidad de elementos ahora si es: " << realSize << "\n";

    int length = array2.size();

    cout << "La cantidad total de elementos del vector es: " << length << "\n";

    return 0;
}