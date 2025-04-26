#include<iostream>
#include<queue>
#include<map>
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
pair<int,int> solve(node* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> left=solve(root->left);
    pair<int,int> right=solve(root->right);

    pair<int,int> result;
    result.first=root->data+left.second+right.second;
    result.second=max(left.first,left.second)+max(right.first,right.second);

    return result;
}
int getmaxsum(node* root){
    pair<int,int> ans=solve(root);
    return max(ans.first,ans.second);
}
int main() {
    node *root = NULL;
    root = buildtree(root);

    int ans=getmaxsum(root);
    cout<<"Max sum:"<<ans<<endl;
    return 0;
}
