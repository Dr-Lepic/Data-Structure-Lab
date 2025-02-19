#include<bits/stdc++.h>
#include"Task2.h"
using namespace std;

int* RandGen(int n){
    int* arr = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        if(rand()%3 == 0)
            arr[i] = -rand()%101;
        else
        arr[i] = rand()%101;
    }
    return arr;
}

int main(){
    int* arr1 = RandGen(10);
    int* arr2 = RandGen(100);
    int* arr3 = RandGen(1000);

    int check = BubbleSort(arr1, 10);
    cout<<"Bubble Sort:"<<endl;
    cout<<"Checks 10: "<<check<<endl;

    check = BubbleSort(arr2, 100);
    cout<<"Checks 100: "<<check<<endl;

    check = BubbleSort(arr3, 1000);
    cout<<"Checks 1000: "<<check<<endl;

    return 0;

}