#include<iostream>
#include<cmath>

using namespace std;

void heapSort(int array[]){
    int temp = 0;
    for(int i = 1; i < 15; i++){
        for(int j = 15 - i; j > 0; j--){
            int flotante = round((j - 1)/2);
            if(array[j] > array[flotante]){
                temp = array[j];
                array[j] = array[flotante];
                array[flotante] = temp;
            }
        }
        temp = array[0];
        array[0] = array[15 - i];
        array[15 - i] = temp;
    }
}

int main(){
    int arr[] = {6, 1, 5, 60, 13, 2, 78, 41, 11, 14, 18, 38, 484, 23, 1};

    cout << "Los elementos desordenados son: ";
    for(int ele : arr){
        cout << ele << " ";
    } cout << "\n";

    heapSort(arr);

    cout << "Los elementos ordenados son: ";
    for(int ele : arr){
        cout << ele << " ";
    } cout << "\n";
}