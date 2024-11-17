#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    
    stack<char> stk;

    // stk.push(s[0]);
    for(char c : s){
        if(!stk.empty() && stk.top() == c){
            stk.pop();
        }
        stk.push(c);
    }
    if(stk.empty()){cout<<"NULL"; return 0;}

    string ans;

    // while(!stk.empty()){
    //     ans = stk.top() + ans;
    //     stk.pop();
    // }

    // cout<<ans;
    int i = 0;

    while(!stk.empty()){
        char a = stk.top();
        stk.pop();
        ans[i] = a;
        i++;
    }
    for(int i = ans.size()-1; i>=0; i--){
        cout<<ans[i];
    }

    
}