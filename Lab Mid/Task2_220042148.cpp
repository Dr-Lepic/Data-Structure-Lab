#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    string t;

    cin>>s;
    cin>>t;

    if(s.size() != t.size()){
        cout<<"No";
        return 0;
    }

    string ans;


    //char a[s.size()+1];
    int count = 0;
    while(true){
        if(count>s.size()){
            cout<<"No";
            return 0;
        }
        if(s == t){
            cout<<"Yes";
            return 0;
        }

        
        ans[0] = s[s.size()-1];
        
        for(int i = 1; i<s.size(); i++){
            ans[i] = s[i-1];
        }
        s = ans;
        count++;
    }
    cout<<"Yes";
    return 0;


    // if(ans.find(t)){
    //     cout<<"Yes";
    //     return 0;
    // }
    // else{
    //     cout<<"No";
    //     return 0;
    // }

    
}