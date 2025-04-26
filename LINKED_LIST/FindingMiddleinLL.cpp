#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertathead(node* &head,node* &tail,int d){
    node* temp=new node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
void insertattail(node* &head,node* &tail,int d){
    node* temp=new node(d);
    if(tail==NULL){
        tail=temp;
        head=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}
void insertatpostion(node* &head,node* &tail,int position,int d){
    if(position==1){
        insertathead(head,tail,d);
         return;
    }
    int count=1;
    node* temp=head;
    while(count<position-1 && temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL||temp==NULL){
         insertattail(head,tail,d);
         return;
    }
    node* newnode=new node(d);
    newnode->next=temp->next;
    temp->next=newnode;
}
// int getlength(node* head){
//     if(head == NULL){
//         return 0;
//     }
//     node* temp = head;
//     int count = 0;
//     while(temp != NULL){
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

// node* findingmiddlenode(node* head){
//     node* temp = head;
//     int length = getlength(head);
//     int ans = length / 2;
//     int count = 0;

//     while(count < ans) {
//         temp = temp->next;
//         count++;
//     }

//     return temp;
// }
node* findingmiddlenode(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;  // List is empty or has one element
    }

    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;  // Move fast by two steps
        slow = slow->next;        // Move slow by one step
    }

    return slow;  // Slow will point to the middle node
}

int main(){
    node* head=NULL;
    node* tail=NULL;
    insertathead(head,tail,9);
    insertathead(head,tail,8);
    insertathead(head,tail,7);
    insertathead(head,tail,6);
    insertathead(head,tail,5);
    insertattail(head,tail,10);
    insertattail(head,tail,11);
    insertattail(head,tail,12);
    insertattail(head,tail,13);
    insertattail(head,tail,14);
    insertattail(head,tail,15);
    insertattail(head,tail,16);
    print(head);
    cout<<endl;

    node* m=findingmiddlenode(head);
    cout<<m->data<<endl;
    return 0;
}