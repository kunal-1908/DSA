#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    node *left;
    int data;
    node * right;

    node(int x){
        this->left=nullptr;
        this->data=x;
        this->right=nullptr;
    }
};
void inorder(node *root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelordertraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        node *temp=q.front();
        q.pop();

        if(temp==nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}
node* buildtree(node *root){
    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return nullptr;
    }
    root=new node(data);

    cout<<"enter the data for the left:"<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"enter the data for right:"<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}
void buildfromlevelorder(node* &root){
    queue<node*> q;
    cout<<"enter the data for root node:"<<endl;
    int data;
    cin>>data;

    if(data==-1){
        return;
    }
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"enter the data for left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}
int main(){
    node *root=nullptr;
    buildfromlevelorder(root);
    // inorder(root);
    //10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
    levelordertraversal(root);
    return 0;
}