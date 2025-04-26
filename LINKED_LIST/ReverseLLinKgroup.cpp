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
node* kreverse(node* &head,int n){
    //base case
    if(head==NULL){
        return head;
    }
    node* prev=NULL;
    node* curr=head;
    node* next=NULL;
    int count=0;
    while(curr!=NULL && count<n){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        head->next=kreverse(next,n);
    }
    return prev;
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
    print(head);
    cout<<endl;
    node* m=kreverse(head,4);
    print(m);
    
    return 0;
}