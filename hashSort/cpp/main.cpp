#include<iostream>

using namespace std;

int main(){
    int arr[] = {4, 10, 9, 47, 90, 9, 3, 341, 551, 79, 8};
    cout << "Elementos desordenados" << endl;
    for(int ele : arr){
        cout << ele << " ";
    } cout << endl;

    for(int div = (sizeof(arr)/sizeof(arr[0]) - 1)/2; div >= 1; div /= 2){
        int separation = div;
        for(int i = div; i < sizeof(arr)/sizeof(arr[0]); i++){//los errores de segment fault se daran mayormente debido a recursiones muy profundas, revisar los ciclos cuando eso pase
            int reserve = arr[i];

            int j = i - separation;
            while(j >= 0 && reserve < arr[j]){
                arr[j + separation] = arr[j];

                j -= separation;
            }
            arr[j + separation] = reserve;
        }
    }

    cout << "Elementos ordenados" << endl;
    for(int ele : arr){
        cout << ele << " ";
    } cout << endl;
    return 0;
}