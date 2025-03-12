#include<bits/stdc++.h>
#include"Trie.h"
using namespace std;

int main(){
    Trie trie;

    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i<N; i++){
        string word;
        cin >> word;
        trie.insert(word);
    }

    vector<string> words = trie.display();
    for(const string& word : words){
        cout << word << endl;
    }

    for(int i = 0; i<Q; i++){
        string word;
        cin >> word;
        if(trie.search(word)){
            cout << "T" << endl;
        }
        else{
            cout << "F" << endl;
        }
    }
}