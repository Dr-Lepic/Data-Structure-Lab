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
    
    for (int i = 0; i < 10; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    int check = BubbleSort(arr1, 10);

    for (int i = 0; i < 10; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"Checks: "<<check<<endl;

    int arr2[5] = {5, 2,1, 3, 4}; 
    check = QuickSort(arr2, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    cout<<"Checks: "<<check<<endl;
    return 0;
}