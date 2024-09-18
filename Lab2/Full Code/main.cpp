/*
ID: 220042162
Data Struct Lab 2
*/

#include <iostream>
#include "single_linked_list.h"
#include "my_stack.h"
using namespace std;
int main()
{
    SingleLinkedList<int> ll;
    ll.push_front(3);
    ll.push_front(7);
    ll.push_front(1);
    ll.push_front(5);

    ll.print();

    ll.push_back(0);
    ll.push_back(10);
    ll.push_back(13);

    ll.print();

    my_stack<int> st;
    st.push(3);
    st.push(5);
    st.push(0);

    cout << st.top();

    return 0;
}