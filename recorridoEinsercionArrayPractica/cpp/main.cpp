#include <iostream>

using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int num, position;

    cout << "Los elementos del array son: \n";
    for(int i : arr){
    cout << " " << i;
    }
    cout << "\n";
    cout << "Ingresar nuevo elemento del array: ";
    cin >> num;
    cout << "Ingresar posicion del array: ";
    cin >> position;

    for(int i = sizeof(arr)/sizeof(arr[0])-1; i>position; i--){
        arr[i] = arr[i - 1];
    }
    arr[position] = num;

    cout << "Los elementos del array modificado son: \n";

    for(int i : arr){
        cout << " " << i;
    }
    cout << "\n";
    return 0;
}