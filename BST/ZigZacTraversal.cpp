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
vector<int> zigzactraversal(node* root){
    vector<int> result;
    if(root==NULL){
        return result;
    }

    queue<node*> q;
    q.push(root);
    bool lefttoright=true;

    while(!q.empty()){
        int size=q.size();
        vector<int> ans(size);

        for(int i=0;i<size;i++){
            node *frontnode=q.front();
            q.pop();

            int index=lefttoright?i:size-i-1;
            ans[index]=frontnode->data;

            if(frontnode->left){
                q.push(frontnode->left);
            }
            if(frontnode->right){
                q.push(frontnode->right);
            }
        }
        lefttoright=!lefttoright;

            for(auto i:ans){
                result.push_back(i);
            }
    }
    return result;
}
int main() {
    node *root = NULL;

    root = buildtree(root);
    cout<<"zigzagtraversal:"<<endl;
    vector<int> ans=zigzactraversal(root);
    return 0;
}
