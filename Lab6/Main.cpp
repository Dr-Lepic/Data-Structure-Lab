#include<iostream>
#include"AVLTree.h"
using namespace std;

int main(){
    AVLTree<int> avl;
    avl.insert(1);
    avl.insert(2);
    avl.insert(3);
    avl.insert(4);
    avl.insert(5);
    //avl.insert(15);
    cout<<avl.height()<<endl;
    cout<<avl.front()<<endl;
    cout<<avl.back()<<endl;
    avl.level_order_traversal();
}