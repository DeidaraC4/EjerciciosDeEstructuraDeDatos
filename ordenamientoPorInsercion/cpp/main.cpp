#include<iostream>

using namespace std;

int arr[] = {29, 84, 56, 2, 76, 37, 39, 2};
void printArr(int arr[]){
    for(int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    cout << "El array desordenado es: \n";
    printArr(arr);

    for(int i = 1; i < 8; i++){
        int reserva = arr[i];

        int j = i - 1;
        while(j >= 0 && reserva < arr[j]){
            arr[j + 1] = arr[j];

            j -= 1;
        }
        arr[j + 1] = reserva;
    }

    cout << "El array desordenado es: \n";
    printArr(arr);
    
    return 0;
}