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

node* lowestcommonancestors(node* root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == n1 || root->data == n2) {  // Use OR to check if root matches either n1 or n2
        return root;
    }
    
    node* leftans = lowestcommonancestors(root->left, n1, n2);
    node* rightans = lowestcommonancestors(root->right, n1, n2);

    if(leftans != NULL && rightans != NULL) {
        return root;  // If both left and right are non-NULL, root is the LCA
    }
    else if(leftans != NULL) {
        return leftans;
    }
    else {
        return rightans;
    }
}

int main() {
    node *root = NULL;
    root = buildtree(root);
    // 2 3 10 -1 -1 11 -1 -1 5 4 -1 -1 6 9 -1 -1 -1

    node* ans = lowestcommonancestors(root, 4, 9);
    if(ans != NULL)
        cout << "The lowest common ancestor is: " << ans->data << endl;
    else
        cout << "No common ancestor found." << endl;

    return 0;
}
