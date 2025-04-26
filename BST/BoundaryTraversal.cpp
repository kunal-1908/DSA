#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node(int x) {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root) {
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;

    if(data == -1) {
        return NULL;  // Return NULL when there is no node
    }

    root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}
void traverseleft(node *root,vector<int> &ans){
    if(root==NULL||root->left==NULL&&root->right==NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseleft(root->left,ans);
    }
    else{
        traverseleft(root->right,ans);
    }
}
void traverseleaf(node *root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
    }
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
}
void traverseright(node *root,vector<int> &ans){
    if(root==NULL||root->left==NULL&&root->right==NULL){
        return;
    }
    traverseright(root->right,ans);
    traverseright(root->left,ans);

    ans.push_back(root->data);
}
vector<int> BoundaryTraversal(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    ans.push_back(root->data);
    traverseleft(root->left,ans);
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
    traverseright(root->right,ans);

}
int main() {
    node *root = NULL;

    root = buildtree(root);
    cout<<"BoundaryTraversal:"<<endl;
    vector<int> ans=BoundaryTraversal(root);
    return 0;
}
