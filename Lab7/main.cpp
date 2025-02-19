#include<iostream>
#include"BinaryHeap.h"
using namespace std;

int main(){
    BinaryHeap<int> bh;
    bh.insert(7);
    bh.insert(2);
    cout << bh.top() << endl;
    bh.insert(13);
    cout << bh.top() << endl;
    bh.increase_key(1, 20);
    cout << bh.top() << endl;
    // bh.erase();
    // cout << bh.top() << endl;
    // bh.erase();
    // cout << bh.top() << endl;
}