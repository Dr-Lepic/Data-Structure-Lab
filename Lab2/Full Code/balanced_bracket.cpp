/*
ID: 220042162
Data Struct Lab 2
*/

#include "my_stack.h"
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<char, int> brackets = {
    {'[', -3},
    {'{', -2},
    {'(', -1},
    {')', 1},
    {'}', 2},
    {']', 3}
};

bool is_balanced(string s)
{
    my_stack<char> st;
    for (char ch : s) {
        if (brackets[ch] < 0)
        {

            st.push(ch);
        }
        else if (brackets[ch] > 0)
        {

            if (st.is_empty()) {
                return false;
            }
            char top = st.top();
            st.pop();

            if ((brackets[top] + brackets[ch]) != 0) {
                return false;
            }
        }
        else
        {
            continue;
        }
    }

    return st.is_empty();
}

int main()
{
    string expr1 = "[a*{(b-2)/(a+2)}+3]";
    string expr2 = "[a*{(b-2))/(a+2)}+3]";
    // string expr2 = "[{())()}]";
    cout << ((is_balanced(expr1)) ? "YES\n" : "NO\n");
    cout << ((is_balanced(expr2)) ? "YES\n" : "NO\n");

    return 0;
}