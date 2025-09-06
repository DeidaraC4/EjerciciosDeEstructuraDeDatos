#include <iostream>

using namespace std;

int main(){
    int arr[9];
    int twoDimArr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Los elementos del array bidimensional son:\n";
    int k = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arr[k++] = twoDimArr[i][j];
            cout << twoDimArr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Los elementos del array unidimensional son:\n";
    for(int i : arr){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}