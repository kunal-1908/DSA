#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class stack {
public:
    node* top;

    stack() {
        top = NULL;
    }

    void push(int d) {
        node* newnode = new node(d);
        newnode->next = top;
        top = newnode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack underflow." << endl;
            return;
        }
        node* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }

    int peekElement() {
        if (top == NULL) {
            cout << "Stack underflow." << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void printStack() {
        if (top == NULL) {
            cout << "Stack underflow." << endl;
            return;
        }
        node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    s.printStack();

    return 0;
}
