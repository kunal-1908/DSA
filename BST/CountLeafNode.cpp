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
void inorder(node* root,int &count){
    if(root==NULL) return;

    inorder(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder(root->right,count);
}
int noofleaves(node *root){
    int coutn=0;
    inorder(root,coutn);
    return coutn;
}
int main() {
    node *root = NULL;

    root = buildtree(root);
    cout<<"levelordertraversal: ";
    levelordertraversal(root);

    int n=noofleaves(root);
    cout<<"total no. of leaves are:"<<n<<endl;
    return 0;
}
