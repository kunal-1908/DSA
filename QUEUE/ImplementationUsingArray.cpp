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
        if (rear == capacity - 1) { 
            cout << "Queue overflow." << endl;
            return;
        } else if (front == -1) {  
            front = rear = 0;
            arr[rear] = data;
        } else {
            rear = rear + 1; 
            arr[rear] = data;
        }
    }

    int pop() {
        if (front == -1 || front > rear) {  
            cout << "Queue underflow." << endl;
            return -1; 
        } else {
            int index = front;
            int value = arr[front];
            cout << "Deleted index no. " << index << " having value: " << value << endl;

            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
            return value;
        }
    }

    int qfront() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow." << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    void print() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
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

    q.pop();  
    q.print();

    cout << "Front element: " << q.qfront() << endl;

    return 0;
}
