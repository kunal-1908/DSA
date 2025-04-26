#include<iostream>
using namespace std;

class twostack {
    int *arr;
    int top1;
    int top2;
    int capacity;

public:
    twostack(int size) {
        this->capacity = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int d) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = d;
        } else {
            cout << "Stack Overflow in Stack 1." << endl;
        }
    }

    void push2(int d) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = d;
        } else {
            cout << "Stack Overflow in Stack 2." << endl;
        }
    }

    void pop1() {
        if (top1 >= 0) {
            cout << "Popped element from Stack 1: " << arr[top1] << endl;
            top1--;
        } else {
            cout << "Stack Underflow in Stack 1." << endl;
        }
    }

    void pop2() {
        if (top2 < capacity) {
            cout << "Popped element from Stack 2: " << arr[top2] << endl;
            top2++;
        } else {
            cout << "Stack Underflow in Stack 2." << endl;
        }
    }
};

int main() {
    twostack s(5);
    
    s.push1(10);
    s.push1(20);
    s.push2(30);
    s.push2(40);
    
    s.pop1();
    s.pop2();
    
    return 0;
}
