#include<iostream>
using namespace std;

int BubbleSort(int *arr, int n){
    int check = 0;

    for(int i = n-1; i>0; --i){
        int max = arr[0];

        for(int j = 1; j<= i; j++){
            check++;
            if( arr[j] < max){
                arr[j-1] = arr[j];
                check++;
            }
            else{
                arr[j-1] = max;
                max = arr[j];
                check++;
            }
        }
        arr[i] = max;
    }
    return check;
}

int QuickSort(int *arr, int left, int right){
    int check = 0;
    if(left < right){
        int pivot = arr[right];
        int i = left -1;
        for(int j = left; j < right; j++){
            check++;
            if(arr[j] < pivot){
                i++;
                swap(arr[i], arr[j]);
                check++;
            }
            else{
                check++;
            }
        }
        

    }
}
