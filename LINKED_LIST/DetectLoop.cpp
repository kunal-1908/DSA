#include<iostream>
#include<map>
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

void insertathead(node*& tail, node*& head, int d) {
    node* temp = new node(d);
    if (head == nullptr) {
        head = temp;
        tail = temp;
        temp->next = temp; 
    } else {
        temp->next = head;
        head = temp;
        tail->next = head; 
    }
}

void insertattail(node*& tail, node*& head, int d) {
    node* temp = new node(d);
    if (tail == nullptr) {
        head = temp;
        tail = temp;
        temp->next = temp;
    } else {
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }
}

void insertatposition(node*& tail, node*& head, int position, int d) {
    if (position == 1) {
        insertathead(tail, head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp->next != head) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == head) {
        insertattail(tail, head, d);
        return;
    }

    node* newnode = new node(d);
    newnode->next = temp->next;
    temp->next = newnode;
}
void deletenode(node *&head, node *&tail, int element) {
    if (head == NULL) {
        cout << "The linked list is empty." << endl;
        return;
    }

    if (head->data == element) {
        node *temp = head;
        
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            tail->next = head;
        }
        
        temp->next = NULL;
        delete temp;
        return;
    }

    node *temp = head;
    node *prev = NULL;

    while (temp != tail && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data != element) {
        cout << "Element not found in the list." << endl;
        return;
    }

    if (temp == tail) {
        prev->next = head; 
        tail = prev;    
    } else {
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
// bool detectloop(node* head){
//     if(head==NULL){
//         return false;
//     }
//     node* temp=head;
//     map<node*,bool> visited;
//     while(temp!=NULL){
//         if(visited[temp]==true){
//             cout<<"present on element:"<<temp->data<<endl;
//             return true;
//         }
//         visited[temp]=true;
//         temp=temp->next;
//     }
//     return false;
// }
bool detectloop(node* head) {
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) {
            cout << "Loop is present at: " << slow->data << endl;
            return true;
        }
    }

    return false;
}

int main() {
    node* head = nullptr;
    node* tail = nullptr;

    insertathead(tail, head, 10);
    insertattail(tail, head, 20);
    insertatposition(tail, head, 2, 15);
    insertathead(tail, head, 30);
    insertathead(tail, head, 40);
    print(tail, head);

    if(detectloop(head)){
        cout<<"loop is present."<<endl;
    }
    else{
        cout<<"loop is absent."<<endl;
    }

    return 0;
}
