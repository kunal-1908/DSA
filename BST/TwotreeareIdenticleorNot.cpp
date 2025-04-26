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
bool isidenticle(node *root1,node *root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1!=NULL&&root2==NULL){
        return false;
    }
    if(root1==NULL&&root2!=NULL){
        return false;
    }

    bool left=isidenticle(root1->left,root2->left);
    bool right=isidenticle(root1->right,root2->right);

    bool value=root1->data==root2->data;

    if(left&&right&&value){
        return true;
    }
    else{
        return false;
    }
}
int main() {
    node *root1 = NULL;
    root1 = buildtree(root1);

    node *root2=NULL;
    root2=buildtree(root2);

    levelordertraversal(root1);
    cout<<endl;
    levelordertraversal(root2);
    cout<<endl;

    bool ans=isidenticle(root1,root2);
    if(ans){
        cout<<"both tree are identicle."<<endl;
    }
    else{
        cout<<"both tree are not identicle."<<endl;
    }

    return 0;
}
