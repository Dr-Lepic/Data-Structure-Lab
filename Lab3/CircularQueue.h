#include<iostream>
using namespace std;

template <typename T>
class CircularQueue{
    private:
        int q_size;
        int capacity;
        int ifront;
        int iback;
        T *arr;
    
    public:
        CircularQueue(int capacityi = 6){
            capacity = capacityi;
            arr = new T[capacity];
            q_size = 0;
            ifront = 0;
            iback = -1;
        }

        bool empty() const{
            return q_size == 0;
        }

        int size() const{
            cout<<"Queue size: ";
            return q_size;
        }

        T front() const{
            return arr[ifront];
        }

        void enqueue(T data){
            if(q_size == capacity){
                cout<<"The queue is Full";
                return;
            }

            iback = (iback + 1) % capacity;
            arr[iback] = data;
            cout<<"Enqued: "<<data<<endl;
            q_size++;
            
        }

        T dequeue(){
            if(q_size == 0){
                cout<<"Queue is empty";
                return 1;
            }
            T data = arr[ifront];
            ifront = (ifront + 1) % capacity;
            q_size--;
            cout<<"Dequeued: "<< data << endl;
            return data;
        }

        void show(){
            cout<<"Queue is: ";
            if(empty()){
                cout<<"Empty";
                return;
            }
            for (int i = 0; i < q_size; i++)
            {
                cout<<arr[(ifront + i) % capacity]<<" ";
            }
            
        }

};
