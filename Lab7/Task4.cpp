#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    vector<int> hT;

    for(int i = 0; i < n; i++){
        if(i < 2){
            cout<<-1<<endl;
        }
        hT.push_back(arr[i]);
        sort(hT.begin(), hT.end());
        reverse(hT.begin(), hT.end());

        if(i > 1){
            cout<<hT[0]*hT[1]*hT[2]<<endl;
        }
    }


}