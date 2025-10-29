#include <iostream>
#include <vector>
#include <cmath> // cpp nativamente no deja usar exponenciacion

using namespace std;

void printArray(const vector<int>& arr) {
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {938, 4, 102, 30, 5, 2, 4928, 701, 230, 71, 92, 474, 91, 2};

    cout << "desordenados: ";
    printArray(arr);

    //maximo valor del arreglo
    int max = arr[0];
    for (int ele : arr) {
        if (max < ele) {
            max = ele;
        }
    }

    //contar digitos del numero maximo
    int cont = 1;
    while (1 < max) {
        max /= 10;
        cont++;
    }

    for (int k = 0; k < cont; ++k) {
        for (int i = 1; i < arr.size(); ++i) {
            int reserva = arr[i];
            int j = i - 1;

            //dividir entre 10, 100 ... y sacar su modulo con 10 para obtener el valor del ultimo digito de cada unidad truncada
            int exp = (int)pow(10, k);
            while (j >= 0 && (reserva / exp) % 10 < (arr[j] / exp) % 10) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = reserva;
        }
    }

    cout << "ordenados: ";
    printArray(arr);

    return 0;
}