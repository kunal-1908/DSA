#include<iostream>
using namespace std;

class node {
public:
    node* prev;
    int data;
    node* next;

    node(int data) {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void print(node*& head) {
    if(head==NULL){
        cout<<"the LL is empty."<<endl;
        return;
    }
    node* temp = head;
    while (temp != NULL) {  // corrected condition to include the last node
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertathead(node*& head, node*& tail, int d) {  // added tail as a parameter
    node* newnode = new node(d);  // corrected typo
    if (head == NULL) {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        tail = newnode;  // updated tail when head is NULL
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertattail(node*& tail, node*& head, int d) {  // added head as a parameter
    node* newnode = new node(d);  // corrected typo
    if (tail == NULL) {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        tail = newnode;  // updated tail and head when tail is NULL
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertatposition(node*& head, node*& tail, int position, int d) {
    if (position == 1) {
        insertathead(head, tail, d);  // passing tail as well
        return;
    }

    node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertattail(tail, head, d);  // passing head as well
        return;
    }

    node* node1 = new node(d);  // corrected typo
    node1->next = temp->next;
    temp->next->prev = node1;
    temp->next = node1;
    node1->prev = temp;
}
void deletenode(node *&head,int position){
    if(head==NULL){
        cout<<"the LL is empty."<<endl;
        return;
    }
    else if(position==1){
        node *temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node *temp=head;
        int cnt=1;
        while(cnt<position && temp->next!=NULL){
            temp=temp->next;
            cnt++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->prev=NULL;
        temp->next=NULL;
        delete temp;

    }
}
int main() {
    node* head = NULL;
    node* tail = NULL;

    // Example insertions
    insertathead(head, tail, 10);
    insertattail(tail, head, 20);
    insertatposition(head, tail, 2, 15);
    insertathead(head,tail,34);
    insertathead(head,tail,45);
    insertattail(tail, head, 60);
    insertattail(tail, head, 70);

    print(head);
    deletenode(head,5);
    print(head);
    

    return 0;
}
