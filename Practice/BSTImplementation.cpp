#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insertintobst(node* &root, int data){
    if(root == nullptr){
        root = new node(data);
        return;
    }
    if(data > root->data){
        insertintobst(root->right, data); 
    }
    else{
        insertintobst(root->left, data); 
    }
}

void takeinput(node* &root){
    int data;
    cin >> data;

    while(data != -1){
        insertintobst(root, data); 
        cin >> data;
    }
}

int main(){
    node* root = nullptr;
    cout << "Enter data to create BST:" << endl;
    takeinput(root);
    return 0;
}
