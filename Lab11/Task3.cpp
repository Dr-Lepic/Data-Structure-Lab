#include<bits/stdc++.h>
#include"Trie.h"
using namespace std;

int main(){
    Trie trie;

    int N;
    cin >> N;

    for(int i = 0; i<N; i++){
        string word;
        cin >> word;
        trie.insert(word);
    }

    string temp;
    
    while (true)
    {
        cin >> temp;
        if(temp == "-1") break;
        vector<string> suggestion = trie.showSuggestions(temp);
        for(string s : suggestion){
            cout << s << endl;
        }
        cout<<endl;
    }
    return 0;
    
}