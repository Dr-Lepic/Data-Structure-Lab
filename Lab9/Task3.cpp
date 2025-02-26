#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, string> lang;
    string words;

    while(getline(cin, words) && !words.empty()){
        int space = words.find(' ');
        if(space != string::npos){

            string eng = words.substr(0, space);
            string foreign = words.substr(space+1);
            lang[foreign] = eng;
            
        }
    }

    while(getline(cin, words) && !words.empty()){
        if(lang.find(words) != lang.end()){
            cout << lang[words] << endl;
        }
        else{
            cout << "eh" <<endl;
        }
    }

    return 0;
}