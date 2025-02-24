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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int medianOfThree(int *arr, int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid])
        swap(&arr[left], &arr[mid]);
    if (arr[left] > arr[right])
        swap(&arr[left], &arr[right]);
    if (arr[mid] > arr[right])
        swap(&arr[mid], &arr[right]);
    return mid;
}

int QuickSort(int *arr, int left, int right){
    int check = 0;
    if(left < right){
        int median = medianOfThree(arr, left, right);        
        int i = left - 1;
        for(int j = left; j < right; j++){
            check++;
            if(arr[j] < median){
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i+1], &arr[right]);
        check++;
        int pi = i+1;
        check += QuickSort(arr, left, pi-1);
        check += QuickSort(arr, pi+1, right);
    }
    return check;
}

