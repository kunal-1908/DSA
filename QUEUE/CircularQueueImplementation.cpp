#include<iostream>
using namespace std;

class queue {
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    queue(int n) {
        this->capacity = n;
        arr = new int[capacity];
        rear = -1;
        front = -1;
    }

    void enqueue(int data) {
        if ((front == 0 && rear == capacity - 1) || (rear + 1) % capacity == front) {
            cout << "Queue overflow." << endl;
            return;
        } else if (front == -1) { 
            front = rear = 0;
        } else if (rear == capacity - 1 && front != 0) { 
            rear = 0;
        } else { 
            rear++;
        }
        arr[rear] = data;
    }

    int pop() {
        if (front == -1) {
            cout << "Queue underflow." << endl;
            return -1;
        }
        int ans = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
        return ans;
    }

    int qfront() {
        if (front == -1) {
            cout << "Queue underflow." << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    // Print elements of the queue
    // void print() {
    //     if (front == -1) {  // Check if queue is empty
    //         cout << "Queue is empty." << endl;
    //         return;
    //     }
    //     cout << "Queue elements: ";
    //     if (rear >= front) {
    //         // Print elements from front to rear
    //         for (int i = front; i <= rear; i++) {
    //             cout << arr[i] << " ";
    //         }
    //     } else {
    //         // Print in circular order
    //         for (int i = front; i < capacity; i++) {
    //             cout << arr[i] << " ";
    //         }
    //         for (int i = 0; i <= rear; i++) {
    //             cout << arr[i] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    void print(){
        if(front==-1){
            cout<<"queue underflow."<<endl;
            return;
        }
        int index=front;
        do{
            cout<<arr[index]<<" ";
            index=(index+1)%capacity;
        }
        while(index != (rear + 1) % capacity);
    }
};

int main() {
    queue q(10); 
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.print();  

    // q.pop();  
    // q.print();

    // cout << "Front element: " << q.qfront() << endl;

    return 0;
}
