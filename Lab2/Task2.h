#include<iostream>
#include"SingleList.h"
using namespace std;

class MyStack{
    private:
        SingleList list;
    public:
        char top_element(){
            return list.front();
        }
        void push_front1(char a){
            list.push_front(a);
        }
        char pop_front1(){
            list.pop_front();
        }
        bool isEmpty(){
            return list.empty();
        }
        
};