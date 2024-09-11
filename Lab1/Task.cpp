#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
     while (low >= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid - 1;


        else
            high = mid + 1;
    }

    return -1;
}



class myIntSet{
    int size;
    int arr[100000];

    public:
        myIntSet(){
            size = 0;
        }

        int getSize(){
            return size;
        }

        int getElem(int i){
            return arr[i];
        }

        void getSet(){
            cout<<"Set elements: { ";
            for (int i = 0; i < size; i++)
            {
                cout<<arr[i]<<", ";
            }
            cout<<"}"<<endl;
            
        }

        void insert(int num){
            if(size==0){
                arr[0] = num;
                size++;
                return;
            }
            else if(arr[0]<num){
                for (int i = size; i > 0; i--)
                {
                    arr[i] = arr[i-1];
                }
                arr[0] = num;
                size++;
                return;
            }
            else if(arr[size-1] > num){
                arr[size]= num;
                size++;
                return;
            }
            for (int i = 0; i <= size; i++)
            {
                if(arr[i]==num)return;
                else if(arr[i] > num && arr[i+1]<num){
                    for (int j = size; j > i+1; j--)
                    {
                        arr[j] = arr[j-1];
                    }
                    arr[i+1] = num;
                    size++;
                    return;
                }
            }
            
        }

        int find(int num){
            return binarySearch(arr, size -1, 0, num);
        }

        bool erase(int num){
            int index = find(num);
            if (index == -1){return false;}
            for(int i = index; i < size;i++ ){
                arr[i] = arr[i+1];
            }
            size--;
            return true;
            
        }

        bool erase(int indx1, int indx2){
            if(indx1<0){return false;}
            else if(indx2>size){return false;}

            int d = indx2 - indx1 + 1;
            for (int i = indx1; i < size; i++)
            {
                arr[i] = arr[i+d];
            }
            size-=d;
            return true;
        }
};


int main(){
    myIntSet s;

    s.insert(1);
    s.insert(1);
    s.insert(3);
    s.insert(7);
    s.insert(10);
    s.insert(4);
    s.insert(14);
    s.getSet();
    cout<<s.find(3)<<endl;
    cout<<s.find(99)<<endl;
    s.erase(3);
    s.erase(-1,9);
    s.erase(2,4);
    s.getSet();
    cout<<"Size: "<<s.getSize()<<endl;
    

}