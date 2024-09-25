#include<iostream>
#include"CircularQueue.h"
using namespace std;

int main(){

    CircularQueue<int> myQueue(5);

    cout<<myQueue.size()<<endl;;

    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);

    
    myQueue.show();

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.show();
    cout<<endl;
    cout<<"Is empty: "<<myQueue.empty()<<endl;
}