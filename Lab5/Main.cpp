#include<iostream>
#include<bits/stdc++.h>
#include"BinarySearchTree.h"
using namespace std;

int main(){
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(6);
    bst.insert(8);
    cout<<bst.size()<<endl;
    bst.erase(7);
    cout<<bst.size()<<endl;
    cout<<bst.height()<<endl;
    cout<<bst.front()<<endl;
    bst.level_order_traversal();
}