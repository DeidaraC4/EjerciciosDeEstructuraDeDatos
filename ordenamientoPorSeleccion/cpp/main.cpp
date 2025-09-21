#include<iostream>

using namespace std;

int arr[] = {45, 62, 41, 41, 34, 31, 87, 99, 86, 15};

void printArr(int arr[]){
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    cout << "El array desordenado es:\n";
    printArr(arr);

    for(int i = 0; i < 10; i++){
        int little = i;

        for(int j = i + 1; j < 10; j++){
            if(arr[little] > arr[j]){
                little = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[little];
        arr[little] = temp;
    }

    cout << "El array ordenado es:\n";
    printArr(arr);
    return 0;
}