#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main(){

    BinaryTree<int> t;

    t.createRoot(1);
    t.getRoot()->insertLeft(2);
    t.getRoot()->insertRight(3);
    t.getRoot()->getLeft()->insertLeft(4);
    t.getRoot()->getLeft()->insertRight(5);
    t.getRoot()->getRight()->insertLeft(6);
    t.getRoot()->getRight()->insertRight(7);

    // cout<<t.rootValue()<<endl;
    // cout<<t.getRoot()->getLeft()<<endl;
    // cout<<t.getRoot()->getRight();

    cout<<"Size: "<<t.size()<<endl;
    cout<<"Height: "<<t.height()<<endl;
    t.DFS_traversal();
}