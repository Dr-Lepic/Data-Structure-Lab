#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, bool> numbers;
    int num;
    bool flag = true;

    while(cin >> num && num != -1){
        numbers[num] = true;
    }

    while(cin >> num && num != -1){
        if(numbers.find(num) == numbers.end()){
            flag = false;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
}