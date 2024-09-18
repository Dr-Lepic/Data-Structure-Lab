/*
ID: 220042162
Data Struct Lab 2
*/

#include "my_stack.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input = "Hello World";
    string res = "";
    my_stack<char> st;
    for (char ch: input) {
        if (ch != ' ') {
            st.push(ch);
        }
        else
        {
            while (!st.is_empty()) {
                res += st.top();
                st.pop();
            }
            res += ' ';
        }
    }

    while (!st.is_empty()) {
        res += st.top();
        st.pop();
    }

    cout << res << "\n";


    return 0;
}