#include <iostream>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromheap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }
        
        // Move the last element to the root and reduce size
        arr[1] = arr[size];
        size--;

        // Heapify the heap from the root
        int i = 1;
        while (i <= size) {
            int leftchild = 2 * i;
            int rightchild = 2 * i + 1;
            int largest = i;

            // Find the largest among root, left child, and right child
            if (leftchild <= size && arr[leftchild] > arr[largest]) {
                largest = leftchild;
            }
            if (rightchild <= size && arr[rightchild] > arr[largest]) {
                largest = rightchild;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest; // Continue heapifying down the tree
            } else {
                return;
            }
        }
    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(90);
    h.insert(60);
    h.insert(70);
    h.insert(80);
    h.insert(10);
    h.insert(20);
    h.insert(40);

    cout << "Heap before deletion: ";
    h.print();

    h.deletefromheap();

    cout << "Heap after deletion: ";
    h.print();

    return 0;
}
