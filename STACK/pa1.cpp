#include <iostream>
using namespace std;

// Define a node for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top;  // Top pointer for the stack

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;  // Link new node to the previous top
        top = newNode;  // Update the top pointer
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack underflow. Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;  // Move top to the next node
        delete temp;  // Delete the old top node
    }

    // Peek operation to get the top element
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Print the stack
    void printStack() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to test the stack implementation
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Stack contents: ";
    s.printStack();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Stack after pop: ";
    s.printStack();

    cout << "Top element: " << s.peek() << endl;

    return 0;
}
