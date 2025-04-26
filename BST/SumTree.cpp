#include<iostream>
#include<queue>
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
void levelordertraversal(node *root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);  // Marker for the end of the current level

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);  // Add marker for the next level
            }
        } else {
            cout << temp->data << " ";
            
            if (temp->left) {
                q.push(temp->left);
            }
            
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}
pair<bool,int> solve(node *root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL&&root->right==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<bool,int> left=solve(root->left);
    pair<bool,int> right=solve(root->right);

    bool leftans=left.first;
    bool rightans=right.first;
    int leftsum=left.second;
    int rightsum=right.second;

    bool condn=root->data==leftsum+rightsum;
    pair<bool,int> ans;

    if(leftans&&rightans&&condn){
        ans.first=true;
        ans.second=root->data+leftsum+rightsum;
    }
    else{
        ans.first=false;
    }
    return ans;
}
bool issumtree(node *root){
    return solve(root).first;
}
int main() {
    node *root = NULL;

    root = buildtree(root);
    cout<<"levelordertraversal: ";
    levelordertraversal(root);

    bool ans=issumtree(root);
    if(ans){
        cout<<"true sumtree."<<endl;
    }
    else{
        false;
    }
    return 0;
}
