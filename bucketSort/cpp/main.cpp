#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<vector<float>> bucket(10);
    float arr[] = {0.93, 0.4, 0.50, 0.34, 0.94, 0.90, 0.94, 0.992, 0.42, 0.34, 0.42, 0.33, 0.25, 0.2, 0.04, 0.19, 0.52, 0.07, 0.32};

    cout << "los elementos desordenados de la lista son" << endl;
    for(float ele : arr){
        cout << ele << " ";
    } cout << endl;

    for(float ele : arr){
        bucket[(int)ele*10].push_back(ele);
    }

    int index = 0;
    for(vector<float> lista : bucket){
        sort(lista.begin(), lista.end());
        for(float ele : lista){
            arr[index++] = ele;
        }
    }

    cout << "los elementos ordenados de la lista son" << endl;
    for(float ele : arr){
        cout << ele << " ";
    } cout << endl;

    return 0;
}