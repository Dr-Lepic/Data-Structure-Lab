#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i*i <= n; i+=6){
        if(n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

int largestPrime(int N){
    for(int i = N; i >= 2; i--){
        if(isPrime(i)) return i;
    }
    return 2;
}

int main(){
    int choice, N, Q, S, x;
    cin >> choice >> N >> Q >> S;
    vector<int> hashTable(N, -1);
    int count = 0;

    for(int q = 0; q<Q; q++){
        cin>>x;
        bool inserted = false;
        int h1 = x % N;
        int h2 = 0;

        if (choice == 3){
            if (N > 1){
                int prime = largestPrime(N);
                h2 = prime - (x % prime);
            }
            else{
                h2 = 1;
            }
        }

        for(int i = 0; i<6; i++){
            int index;
            switch(choice){
                case 1:
                    index = (h1 + i) % N;
                    break;
                case 2:
                    index = (h1 + i * i) % N;
                    break;
                case 3:
                    index = (h1 + i * h2) % N;
                    break;
                default:
                    index = -1;
                    break;
            }

            if(index < 0 || index >= N) continue;

            if(hashTable[index] == -1){
                hashTable[index] = x;
                count++;
                inserted = true;
                double lf = static_cast<double>(count) / N;
                cout<< "Inserted: Index-" << index << " (L.F=" << setprecision(3) << lf << ")" << endl;
                break;
            }
            else{
                cout << "Collision: Index-" << index << endl;
            }
        }

        if(!inserted){
            cout << "Input Abandoned" << endl;
        }
    } 

    //search
    for(int j = 0; j< S; j++){
        int x;
        cin>>x;
        bool found = false;
        int h1 = x % N;
        int h2 = 0;

        if(choice == 3){
            if (N > 1){
                int prime = largestPrime(N);
                h2 = prime - (x % prime);
            }
            else{
                h2 = 1;
            }
        }

        for (int i = 0; i < 6; ++i) {
            int index;
            switch (choice) {
                case 1:
                    index = (h1 + i) % N;
                    break;
                case 2:
                    index = (h1 + i * i) % N;
                    break;
                case 3:
                    index = (h1 + i * h2) % N;
                    break;
                default:
                    index = -1;
                    break;
            }
            if (index < 0 || index >= N) continue;

            if (hashTable[index] == x) {
                cout << "Found : Index-" << index << endl;
                found = true;
                break;
            } else if (hashTable[index] == -1) {
                break;
            }
        }
        if(!found){
            cout << "Not Found" << endl;
        }
    }

}



