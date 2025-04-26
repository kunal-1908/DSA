#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* head) {
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}
Node* reverse(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newhead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newhead;
}

void insert(Node* &head, Node* &tail, int d) {
    Node* node1 = new Node(d);

    if (head == NULL) {
        head = node1;
        tail = node1;
        return;
    }
    tail->next = node1;
    tail = node1;
}

Node* solve(Node* first, Node* second) {
    int carry = 0;
    Node* anshead = NULL;
    Node* anstail = NULL;

    while (first != NULL || second != NULL || carry != 0) {

        int val1 = 0;
        if (first != NULL) {
            val1 = first->data;
        }

        int val2 = 0;
        if (second != NULL) {
            val2 = second->data;
        }

        int sum = carry + val1 + val2;
        int ans = sum % 10;

        insert(anshead, anstail, ans);
        carry = sum / 10;

        if (first != NULL) {
            first = first->next;
        }
        if (second != NULL) {
            second = second->next;
        }
    }
    return anshead;
}

Node* sum(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);

    Node* ans = solve(first, second);

    ans = reverse(ans);

    return ans;
}

int main() {
    Node* node1 = new Node(10);

    Node* firsthead = node1; 
    Node* firsttail = node1;

    insertAtHead(firsthead, 8);
    insertAtHead(firsthead, 6);
    insertAtHead(firsthead, 4);
    print(firsthead);
    cout << endl;

    Node* node2 = new Node(20);
    Node* secondhead = node2;
    Node* secondtail = node2;

    insertAtHead(secondhead, 15);
    insertAtHead(secondhead, 9);
    insertAtHead(secondhead, 7);
    insertAtHead(secondhead, 5);
    print(secondhead);

    Node* Ans=sum(firsthead,secondhead);
    print(Ans);

    return 0;
}
