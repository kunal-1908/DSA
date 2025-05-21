#include<iostream>
using namespace std;
class node{
    public:
    node *left;
    node *right;
    int data;

    node(int d){
        this->data=d;
        this->left=nullptr;
        this->right=nullptr;
    }
};

node *buildtree(node *root){

    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return nullptr;
    }

    cout<<"enter data for inserting in left of:"<<data<<endl;
    root->left=buildtree(root->left);

    cout<<"enter data for inserting in right of:"<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}

int main(){

    node *root=nullptr;
    root=buildtree(root);
    return 0;
}