#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, int> numbers;
    int num;
    int temp = -1;
    bool flag = true;
    int i = 0;

    while(cin >> num && num != -1){
        numbers[num] = i;
        i++;
    }

    while(cin >> num && num != -1){
        
        if(numbers.find(num) == numbers.end()){
            flag = false;
        }
        else if(temp > numbers[num]){
            flag = false;
            break;
        }
        else{
            temp = numbers[num];
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
}