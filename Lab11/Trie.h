#include<bits/stdc++.h>
using namespace std;

class TriNode{
    public:
        TriNode* children[26];
        bool is_word;

        TriNode(){
            is_word = false;
            for(int i = 0; i<26; i++){
                children[i] = nullptr;
            }
        }
};

class Trie {
    private:
        TriNode* root;

        void dfs(TriNode* node, string prefix, vector<string>& words){
            if(node->is_word){
                
                words.push_back(prefix);
                
            }
            for(int i = 0; i<26; i++){
                if(node->children[i]){
                    char ch = 'a' + i;
                    dfs(node->children[i], prefix + ch, words);
                }
            }
        }
    public:
        Trie(){
            root = new TriNode();
        }

        void insert(const string& word){
            TriNode* current = root;
            for(char ch : word){
                int index = tolower(ch) - 'a';
                if(!current->children[index]){
                    current->children[index] = new TriNode();
                }
                current = current->children[index];
            }
            current->is_word = true;
        }

        bool search(const string& word){
            TriNode* current = root;
            for(char ch : word){
                int index = tolower(ch) - 'a';
                if(!current->children[index]){
                    return false;
                }
                current = current->children[index];
            }
            return current->is_word;
        }

        vector<string> display(){
            vector<string>words;
            dfs(root, "", words);
            return words;
        }

        int countWords(TriNode* node){
            if(!node){
                return 0;
            }
            int count = node->is_word ? 1 : 0;
            for(int i = 0; i<26; i++){
                count += countWords(node->children[i]);
            }
            return count;
        }

        int afterPrefixWordCount(const string& prefix){
            TriNode* current = root;
            for(char ch : prefix){
                int index = tolower(ch) - 'a';
                if(!current->children[index]){
                    return 0;
                }
                current = current->children[index];
            }
            return countWords(current);
        }

        vector<string> showSuggestions(const string& prefix){
            vector<string> suggestions;
            TriNode* current = root;
            for(char ch : prefix){
                int index = tolower(ch) - 'a';
                if(!current->children[index]){
                    return suggestions;
                }
                current = current->children[index];
                dfs(current, prefix, suggestions);
                if(suggestions.size() > 3){
                    suggestions.resize(3);
                }
                
            }
            return suggestions;
        }


} ;