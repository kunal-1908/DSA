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
void insert(Node* &tail,Node* &temp){
    tail->next=temp;
    tail=temp;
}
void sort(Node* &head){
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;
    Node* onehead=new Node(-1);
    Node* onetail=onehead;
    Node* twohead=new Node(-1);
    Node* twotail=twohead;

    Node*temp=head;
    //create seperate list for 0,1,2
    while(temp!=0){
        int value=temp->data;
        if(value==0){
            insert(zerotail,temp);
        }
        else if(value==1){
            insert(onetail,temp);
        }
        else{
            insert(twotail,temp);
        }
        temp=temp->next;
    }
    //merge 3 list
    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    if(twohead->next!=NULL){
        onetail->next=twohead->next;
        twotail->next=NULL;
    }
    head=zerohead->next;
}
int main() {
    Node* node1 = new Node(0);
    Node* head = node1; 
    Node* tail = node1;

    insertAtTail(tail,1);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    insertAtTail(tail,0);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,0);
    insertAtTail(tail,0);
    insertAtTail(tail,2);
    insertAtTail(tail,0);
    print(head);

    sort(head);
    print(head);
    
    return 0;
}
