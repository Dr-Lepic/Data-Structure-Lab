#include<iostream>
#include"CircularQueue.h"
using namespace std;

int main(){

    int a;
    int arr[10000];
    int count = 0;
    for(int i=0; ;i++){
        cin>>a;
        if (a == - 1)
        {
            break;
        }
        arr[i] = a;
        count++;
        
    }
    // for (int i = 0; i < count; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    int k;
    cin>>k;
    //cout<<k;
    CircularQueue<int> q_ticket(count);
    for (int i = 0; i < count; i++)
    {
        q_ticket.enqueue(arr[i]);
    }
    //q_ticket.show();
    int index = k;
    int time = 0;
    while(1){
        int temp = q_ticket.dequeue();
        temp--;
        
        time++;
        if (temp <= 0 && index == 0 )
        {
            cout<<time;
            break;
        }
        else if(temp>0){
            q_ticket.enqueue(temp);
            index--;
        }
        if(index == 0){
            index = index + count - 1;
        }
        if(temp == 0){
            count--;
            index--;
        }
        
    }


}