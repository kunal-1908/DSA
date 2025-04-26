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
node* kthancestor(node* root, int &k, int nodes) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == nodes) {
        return root;
    }

    node* leftans = kthancestor(root->left, k, nodes);
    node* rightans = kthancestor(root->right, k, nodes);

    if (leftans != NULL || rightans != NULL) {
        k--;  // Decrement k as we move up the ancestor chain
        if (k == 0) {
            // If k reaches 0, current node is the k-th ancestor
            return root;
        }
        // Return the non-null answer from left or right
        return (leftans != NULL) ? leftans : rightans;
    }

    return NULL;
}

int main() {
    node *root = NULL;
    root = buildtree(root);
    int k=2;
    int nodes=5;

    node* ans=kthancestor(root,k,nodes);
    cout<<"total no of such path is:"<<ans->data<<endl;
    return 0;
}
