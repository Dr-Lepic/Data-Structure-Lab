#include<iostream>
#include"CircularQueue.h"
using namespace std;

int main(){
    int n;
    cin>>n;
    CircularQueue<int> pep(n);
    CircularQueue<int> san(n);
    int a;
    for(int i = 0; i<n; i++){
        cin>>a;
        pep.enqueue(a);
    }
    for(int i = 0; i<n; i++){
        cin>>a;
        san.enqueue(a);
    }

    // pep.show();
    // san.show();

    while(1){
        
        if(san.empty()){
            cout<<"Unable to eat: ";
            cout<<pep.size();
            break;
        }
        if(pep.front() == san.front()){
            pep.dequeue();
            san.dequeue();
        }else{
            int temp = pep.dequeue();
            pep.enqueue(temp);
        }
    }



}