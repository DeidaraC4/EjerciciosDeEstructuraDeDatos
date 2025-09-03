#include<iostream>

using namespace std;

int main(){
    int num;
    int counter = 0;
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Inserte un numero para conocer su disponibilidad: \n";
    cin >> num;

    for(int i : arr){
        if(i == num){
            cout << "Existe";
            break;
        } else if(counter == sizeof(arr)/sizeof(arr[0]) - 1){
            cout << "No existe";
            break;
        }
        counter += 1;
    }
    cout << "\n";
}