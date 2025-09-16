#include<iostream>

using namespace std;

int main(){
    int arr[] = {64, 39, 82, 37, 49, 21, 18, 54, 21, 34, 87, 21, 32, 41, 23, 23, 67, 98, 43, 56};
    int bubble = 0;
        
        
    cout << "los elementos del array desordenado son:\n";
    for (int ele : arr){
        cout << ele << " ";
    }
    cout << "\n";

        for (int i = 0; i < 19; i++){
            for (int j = 0; j < 19 - i; j++){
                if (arr[j] > arr[j+1]){
                    bubble = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = bubble;
                }
            }
        }

    cout << "los elementos del array ordenado son:\n";
    for (int ele : arr){
        cout << ele << " ";
    }
    cout << "\n";
    return 0;
}