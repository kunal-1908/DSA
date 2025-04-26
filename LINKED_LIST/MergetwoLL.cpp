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

Node* solve(Node* firsthead, Node* secondhead) {
    if(firsthead->next==NULL){
        firsthead->next=secondhead;
        return firsthead;
    }
    Node* curr1 = firsthead;
    Node* next1 = firsthead->next;
    Node* curr2 = secondhead;
    Node* next2 = secondhead->next;

    while (next1 != NULL && curr2 != NULL) {
        if (curr1->data < curr2->data && next1->data > curr2->data) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        } 
        else {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL) {
                curr1->next = curr2;
                return firsthead;
            }
        }
    }

    return firsthead;
}

Node* merge(Node* firsthead, Node* secondhead) {
    if (firsthead == NULL) {
        return secondhead;
    }
    if (secondhead == NULL) {
        return firsthead;
    }
    if (firsthead->data <= secondhead->data) {
        return solve(firsthead, secondhead);
    } else {
        return solve(secondhead, firsthead);
    }
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
    
    firsthead = merge(firsthead, secondhead);
    print(firsthead);

    return 0;
}
