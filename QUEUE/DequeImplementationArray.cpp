#include<iostream>
using namespace std;

class deque {
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    deque(int size) {
        this->capacity = size;
        front = rear = -1;
        arr = new int[capacity];
    }

    bool isempty() {
        return (front == -1);
    }

    bool isfull() {
        if ((front == 0 && rear == capacity - 1) || (front != 0 && (rear + 1) % capacity == front)) {
            return true;
        }
        else {
            return false;
        }
    }

    void pushfront(int data) {
        if (isfull()) {
            cout << "stack overflow." << endl;
            return;
        }
        else if (isempty()) {
            front = rear = 0;
        }
        else if (front == 0 && rear != capacity - 1) {
            front = capacity - 1;
        }
        else {
            front--;
        }
        arr[front] = data;
    }

    void pushrear(int data) {
        if (isfull()) {
            cout << "stack overflow." << endl;
            return;
        }
        else if (isempty()) {
            front = rear = 0;
        }
        else if (rear == capacity - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = data;
    }

    int popfront() {
        if (isempty()) {
            cout << "queue underflow." << endl;
            return -1;
        }
        int ans = arr[front];
        if (front == rear) {  // Only one element present
            front = rear = -1;
        }
        else if (front == capacity - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return ans;
    }

    int popback() {
        if (isempty()) {
            cout << "queue underflow." << endl;
            return -1;
        }
        int ans = arr[rear];
        if (front == rear) {  // Only one element present
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = capacity - 1;
        }
        else {
            rear--;
        }
        return ans;
    }

    int getfront() {
        if (isempty()) {
            cout << "queue underflow." << endl;
            return -1;
        }
        return arr[front];
    }

    int getrear() {
        if (isempty()) {
            cout << "queue underflow." << endl;
            return -1;
        }
        return arr[rear];
    }

    void print() {
        if (isempty()) {
            cout << "queue underflow." << endl;
            return;
        }

        if (front > rear) {
            for (int i = front; i < capacity; i++) {
                cout << arr[i] << " ";
            }
            for (int j = 0; j <= rear; j++) {
                cout << arr[j] << " ";
            }
        }
        else {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    deque d(10);
    d.pushfront(10);
    d.pushrear(20);
    d.pushfront(30);
    d.pushfront(40);
    d.pushrear(50);
    d.pushrear(60);

    d.print();
    return 0;
}
