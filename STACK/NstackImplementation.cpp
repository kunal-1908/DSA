#include <iostream>
#include <vector>
using namespace std;

class NStack {
    int *arr;       // Array to store elements
    int *top;       // Array to store indexes of top elements of stacks
    int *next;      // Array to store next entry in all stacks and free list
    int n, size;    // n = number of stacks, size = size of array
    int freeTop;    // Index of the first free slot in the array

public:
    // Constructor to initialize n stacks in an array of size s
    NStack(int n, int s) {
        this->n = n;
        this->size = s;
        arr = new int[size];    
        top = new int[n];      
        next = new int[size]; 

        // Initialize all stacks as empty
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize all spaces as free
        for (int i = 0; i < size - 1; i++) {
            next[i] = i + 1;
        }
        next[size - 1] = -1;    // -1 indicates end of the free list

        freeTop = 0;            // The first free index is 0
    }

    // Function to push an element x to stack number stackNum
    bool push(int x, int stackNum) {
        if (freeTop == -1) {
            cout << "Stack Overflow\n";
            return false;
        }

        // Find the first free index
        int index = freeTop;

        // Update freeTop to the next free slot
        freeTop = next[index];

        // Insert element into array
        arr[index] = x;

        // Update next and top arrays
        next[index] = top[stackNum];
        top[stackNum] = index;

        return true;
    }

    // Function to pop an element from stack number stackNum
    int pop(int stackNum) {
        if (top[stackNum] == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }

        // Get the top index for this stack
        int index = top[stackNum];

        // Update top to the next element in the stack
        top[stackNum] = next[index];

        // Add the index to the free list
        next[index] = freeTop;
        freeTop = index;

        return arr[index];  // Return the popped element
    }

    // Function to peek at the top element of stack number stackNum
    int peek(int stackNum) {
        if (top[stackNum] == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }

        return arr[top[stackNum]];
    }
};

int main() {
    int n = 3, size = 10;
    NStack stacks(n, size);

    // Let's push elements in stack 1, 2, and 3
    stacks.push(10, 0); // Push 10 to stack 1
    stacks.push(20, 1); // Push 20 to stack 2
    stacks.push(30, 2); // Push 30 to stack 3
    stacks.push(40, 0); // Push 40 to stack 1
    stacks.push(50, 1); // Push 50 to stack 2

    // Let's pop elements from stack 1, 2, and 3
    cout << "Popped from stack 1: " << stacks.pop(0) << endl;
    cout << "Popped from stack 2: " << stacks.pop(1) << endl;
    cout << "Popped from stack 3: " << stacks.pop(2) << endl;

    // Let's peek at the top elements
    cout << "Top of stack 1: " << stacks.peek(0) << endl;
    cout << "Top of stack 2: " << stacks.peek(1) << endl;
    cout << "Top of stack 3: " << stacks.peek(2) << endl;

    return 0;
}
