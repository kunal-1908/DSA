#include <iostream>
#include <queue>
using namespace std;

class kqueue {
public:
    int n;
    int k;
    int *arr;
    int *next;
    int *front;
    int *rear;
    int freespot;

public:
    kqueue(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        
        // Initialize front and rear for each queue
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }
        
        // Initialize next array and freespot
        next = new int[n];
        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        freespot = 0;
    }

    void push(int x, int qn) {
        if (qn < 1 || qn > k) {
            cout << "Invalid queue number." << endl;
            return;
        }

        if (freespot == -1) {
            cout << "No empty space present." << endl;
            return;
        }

        // Find the index to push to
        int index = freespot;
        freespot = next[index];

        // If the queue is empty, update front
        if (front[qn - 1] == -1) {
            front[qn - 1] = index;
        } else {
            next[rear[qn - 1]] = index;
        }

        // Update next, rear, and array at the index
        next[index] = -1;
        rear[qn - 1] = index;
        arr[index] = x;
    }

    int pop(int qn){
        if(front[qn-1]==-1){
            cout<<"queue underflow."<<endl;
            return;
        }
        int index=front[qn-1];
        front[qn-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};

int main() {
    kqueue q(10, 3);
    return 0;
}
