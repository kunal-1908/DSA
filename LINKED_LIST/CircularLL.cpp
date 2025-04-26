#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    ~node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};
bool circularloop(node *&head) {
    // If the list is empty, there's no loop
    if (head == NULL) {
        return false;
    }

    node *temp = head->next;

    // Traverse the list to check if we return to the head
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    // If temp == head, it means we found a circular loop
    if (temp == head) {
        return true;
    }

    // Otherwise, it's not circular
    return false;
}

void insertathead(node*& tail, node*& head, int d) {
    node* temp = new node(d);
    if (head == nullptr) {
        head = temp;
        tail = temp;
        temp->next = temp; // point to itself in case of single node
    } else {
        temp->next = head;
        head = temp;
        tail->next = head; // maintain circular nature
    }
}

void insertattail(node*& tail, node*& head, int d) {
    node* temp = new node(d);
    if (tail == nullptr) {
        head = temp;
        tail = temp;
        temp->next = temp; // point to itself in case of single node
    } else {
        tail->next = temp;
        tail = temp;
        tail->next = head; // maintain circular nature
    }
}

void insertatposition(node*& tail, node*& head, int position, int d) {
    if (position == 1) {
        insertathead(tail, head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    // Traverse to the node just before the position
    while (cnt < position - 1 && temp->next != head) {
        temp = temp->next;
        cnt++;
    }

    // If the position is at the end of the list
    if (temp->next == head) {
        insertattail(tail, head, d);
        return;
    }

    // Insertion in between
    node* newnode = new node(d);
    newnode->next = temp->next;
    temp->next = newnode;
}
void deletenode(node *&head, node *&tail, int element) {
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return;
    }

    // Case 1: If the element is found in the head
    if (head->data == element) {
        node *temp = head;
        
        // If there's only one node in the list
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            tail->next = head; // Maintain the circular structure
        }
        
        temp->next = NULL;
        delete temp;
        return;
    }

    // Case 2: Deleting a node that is not the head
    node *temp = head;
    node *prev = NULL;

    // Traverse until we find the node or loop back to the head
    while (temp != tail && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    // If the element is not found
    if (temp->data != element) {
        cout << "Element not found in the list." << endl;
        return;
    }

    // Case 3: If the element is found in the tail
    if (temp == tail) {
        prev->next = head;  // Adjust the previous node to point to head
        tail = prev;        // Update the tail to be the previous node
    } else {
        // Case 4: Element found somewhere in between head and tail
        prev->next = temp->next;
    }

    temp->next = NULL;
    delete temp;
}

void print(node* tail, node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    node* head = nullptr;
    node* tail = nullptr;

    // Example insertions
    insertathead(tail, head, 10);
    insertattail(tail, head, 20);
    insertatposition(tail, head, 2, 15);
    insertathead(tail, head, 30);
    insertathead(tail, head, 40);

    print(tail, head);
    deletenode(head,tail,15);
    print(tail,head);
    deletenode(head,tail,40);
    print(tail,head);
    if(circularloop){
        cout<<"circular loop is present."<<endl;
    }
    else{
        cout<<"circular loop is absent."<<endl;
    }

    return 0;
}
