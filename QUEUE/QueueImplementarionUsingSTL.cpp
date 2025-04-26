#include <iostream>
#include <queue>  // For the queue container
using namespace std;

int main() {
    // Declare a queue of integers
    queue<int> q;

    // Insert elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // Print the front and back elements of the queue
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // Print all elements and empty the queue
    cout << "Queue elements: ";
    while (!q.empty()) {
        // Access the front element
        cout << q.front() << " ";
        // Remove the front element
        q.pop();
    }
    cout << endl;

    return 0;
}
