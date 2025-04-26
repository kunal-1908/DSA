#include <iostream>
#include <stack>
using namespace std;

class queueusingstack {
    stack<int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
        return;
    }

    void pop() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    void print() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        stack<int> tempStack = s2;
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
};

int main() {
    queueusingstack queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);
    queue.push(60);

    queue.print();
    return 0;
}
