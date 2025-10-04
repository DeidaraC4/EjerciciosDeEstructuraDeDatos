#include<iostream>
#include<cmath>

using namespace std;

void merge(int array[], int left, int mid, int right){
    int a1 = mid - left + 1;
    int a2 = right - mid;

    int L[a1];
    int R[a2];

    for(int i = 0; i < a1; i++){
        L[i] = array[left + i];
    }

    for(int j = 0; j < a2; j++){
        R[j] = array[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < a1 && j < a2){
        if (L[i] < R[j]){
            array[k] = L[i];
            i++;
            k++;
        }else{
            array[k] = R[j];
            j++;
            k++;
        }
    }

    while(i < a1){
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < a2){
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[],int left,int right){
    if (left < right){
        int mid = round((right + left)/2);

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main(){
    int arr[] = {34, 1, 48, 71, 29, 12, 303, 81, 8, 315, 3, 4, 32, 52, 53};
    cout << "los elementos desordenados son: " << endl;
    for(int ele : arr){
        cout << ele << " ";
    } cout << endl;

    mergeSort(arr, 0, 14);

    cout << "los elementos ordenados son: " << endl;
    for(int ele : arr){
        cout << ele << " ";
    } cout << endl;
    return 0;
}