#include<iostream>
using namespace std;
#include"SingleList.h"

int main(){
    SingleList test;

    //test.Node();
    cout<<test.empty()<<endl;
    test.push_front('a');
    //test.pop_front();
    test.push_front('b');
    test.push_front('d');
    test.push_front('c');

    test.show();
}