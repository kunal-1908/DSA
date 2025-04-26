#include<iostream>
#include<map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    // new node create
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
    //insert at Start
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

    //inserting at Last Position
    if (temp -> next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

Node* detectLoop(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // Loop detected
        }
    }
    return NULL;
}

Node* getLoopNode(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    // First detect the intersection point (if a loop exists)
    Node* intersection = detectLoop(head);
    if (intersection == NULL) {
        return NULL; // No loop
    }

    // Move one pointer to the head and keep the other at the intersection
    Node* slow = head;
    Node* fast = intersection;

    // Move both pointers one step at a time, they will meet at the loop start
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // The start of the loop
}

int main() {
    // Created a new node
    Node* node1 = new Node(10);
    
    // head pointed to node1
    Node* head = node1; 
    Node* tail = node1;

    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtPosition(tail, head, 5, 11);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);
    insertAtTail(tail, 15);
    
    // Create a loop for testing
    tail->next = head->next->next;

    Node* loopNode = getLoopNode(head);
    
    if (loopNode != NULL) {
        cout << "Loop starts at node with data: " << loopNode->data << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0;
}
