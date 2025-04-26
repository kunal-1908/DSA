#include<iostream>
#include<map>
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

void print(Node* &head) {
    if (head == NULL) {
        cout << "List is empty "<< endl;
        return;
    }
    Node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp -> next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void removeduplicates(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    map<int, bool> visited; 

    while (curr != NULL) {
       
        if (visited[curr->data] == false) {
            visited[curr->data] = true;
            prev = curr; 
        } 
        else {
            Node* nodetodelete = curr;
            prev->next = curr->next;  
            delete nodetodelete; 
        }
        curr = prev->next;
    }
}


int main() {
    Node* node1 = new Node(1);
    Node* head = node1; 
    Node* tail = node1;

    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    print(head);

    removeduplicates(head);
    print(head);
    
    return 0;
}
