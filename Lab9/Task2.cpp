#include<bits/stdc++.h>
using namespace std;

string processWord(string word){
    int start = 0;
    while(start < word.size() && !isalnum(word[start])){
        start++;
    }
    int end = word.size() - 1;
    while(end >= 0 && !isalnum(word[end])){
        end--;
    }
    return (start <= end) ? word.substr(start, end - start + 1) : "";
}

int main(){

    string line;
    getline(cin, line);
    istringstream word(line);
    unordered_map<string, int> wordCount;
    string word2;

    while(word >> word2){
        string processed = processWord(word2);
        if (!processed.empty()) wordCount[processed]++;
    }

    bool first = true;
    for (auto& pair : wordCount) {
        if (pair.second > 1) {
            if (!first) cout << " ";
            cout << pair.first << " " << pair.second;
            first = false;
        }
    }
    cout << endl;
    return 0;

}