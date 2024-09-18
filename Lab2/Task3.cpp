#include<iostream>
#include"Task2.h"
using namespace std;

int main(){
    MyStack temp;
    string st;

    cin>>st;

    for(int i=0; i<st.size(); i++){
        if(st[i] == '(')
        {
            temp.push_front1('(');
        }
        else if(st[i] == ')'){
            if (temp.pop_front1() == st[i])
            {
                continue;
            }
            else{
                cout<<"Dont Match";
                return 0;
            }
        
            
        }
    }
    cout<<"Matched!";
}