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

void inordertraversal(node *root) {
    if(root == NULL) {
        return;
    }
    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
}

void preordertraversal(node *root){
    if(root==NULL){
        return;
    }
    else{
        cout<<root->data<<" ";
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}

void postordertraversal(node *root){
    if(root==NULL){
        return;
    }
    else{
        cout<<root->data<<" ";
        postordertraversal(root->right);
        postordertraversal(root->left);
    }
}

// void levelordertraversal(node *root){
//     queue<node*> q;
//     q.push(root);

//     while(!q.empty()){
//         node *temp=q.front();
//         cout<<temp->data<<" ";
//         q.pop();

//         if(temp->left){
//             q.push(temp->left);
//         }
//         if(temp->right){
//             q.push(temp->right);
//         }
//     }
// }

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

void buildfromlevelorder(node* &root){
    queue<node*> q;

    cout<<"enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp=q.front();
        q.pop();

        cout<<"enter left node for"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter right node for"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main() {
    node *root = NULL;
    buildfromlevelorder(root);
    levelordertraversal(root);

    // root = buildtree(root);
    // cout << "Inorder traversal: ";
    // inordertraversal(root);
    // cout<<endl;
    // cout<<"preordertraversal: ";
    // preordertraversal(root);
    // cout<<endl;
    // cout<<"postordertraversal: ";
    // postordertraversal(root);
    // cout<<endl;
    // cout<<"levelordertraversal: ";
    // levelordertraversal(root);
    return 0;
}
