#include<iostream>

using namespace std;

int getPivot(int array[], int start, int end){
    int temp;
    int i = start - 1;
    int pivot = array[end];

    for(int j = start; j <= end; j++){
        if(array[j] <= pivot){
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    return i;
}

void quickSort(int array[], int start, int end){
    if(end <= start){return;}

    int pivot = getPivot(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
}

int main(){
    
    int arr[] = {78, 64, 91, 73, 40, 15, 91, 36, 47, 51, 67, 19, 34, 69, 2, 1, 36, 4, 49, 7, 25, 94, 53, 5, 2};

    cout << "Los elementos Desordenados son: \n";

    for(int ele : arr){
        cout << ele << " ";
    } cout << "\n Los elementos ordenados son: \n";

    quickSort(arr, 0, 24);

    for(int ele : arr){
        cout << ele << " ";
    } cout << "\n";

    return 0;
}