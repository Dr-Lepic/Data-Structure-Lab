#include <iostream>
using namespace std;

class DynamicQueue {
private:
    int* arr;       
    int capacity;   
    int front;      
    int rear;       
    int size;       

    
    void resize() {
        int newCapacity = 2 * capacity;
        int* newArr = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }

        front = 0;
        rear = size - 1;
        capacity = newCapacity;

        delete[] arr;
        arr = newArr;
    }

public:
    DynamicQueue(int initialCapacity = 5) {
        capacity = initialCapacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~DynamicQueue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == capacity) {
            resize();
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue from an empty queue.\n";
            return -1;
        }

        int value = arr[front];
        front = (front + 1) % capacity;
        size--;

        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int getSize() {
        return size;
    }

    void show_queue(){
        if (rear >front){
            for (int i = front; i <= rear; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        else{
            for (int i = front; i <= size; i++)
            {
                cout<<arr[i]<<" ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
    }

    void print_queue(){
        cout<< "Elements: " ;
        for (int i = 0; i < size; i++) {
            cout<< arr[(front + i) % capacity]<<" ";
        }
    }
    
    int show_capacity(){
        return capacity;
    }
};

int main() {
    DynamicQueue queue(3);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout<<"\nCapacity: " << queue.show_capacity()<<endl;

    queue.enqueue(40);
    queue.enqueue(50);
    cout<<"\nCapacity: " << queue.show_capacity() << endl;

    cout << "Front element is: " << queue.peek() << endl;
    
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    queue.enqueue(60);
    queue.enqueue(70);

    cout << "Front element is: " << queue.peek() << endl;
    cout << "Queue size is: " << queue.getSize() << endl;
    cout << "Elements: " << endl;
    queue.show_queue();
    queue.print_queue();
    return 0;
}