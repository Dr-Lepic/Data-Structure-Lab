#include<bits/stdc++.h>
#include"Trie.h"
using namespace std;

int main(){
    Trie trie;

    int N, Q;
    cin >> N >> Q;
    for(int i=0; i<N; i++){
        string word;
        cin >> word;
        trie.insert(word);
    }
    
    for(int i = 0; i<Q; i++){
        string prefix;
        cin >> prefix;
        cout << trie.afterPrefixWordCount(prefix) << endl;
    }
}