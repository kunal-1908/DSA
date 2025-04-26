#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverse(queue<int> &q, int k) {
    stack<int> s;
    for (int i = 0; i < k; i++) {
        int value = q.front();
        q.pop();
        s.push(value);
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    int t = q.size() - k;
    while (t > 0) {
        int val = q.front();
        q.pop();
        q.push(val);
        t--;
    }
    return;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    reverse(q, 3);
    while (!q.empty()) {
        int val = q.front();
        q.pop();
        cout << val << " ";
    }
    return 0;
}
