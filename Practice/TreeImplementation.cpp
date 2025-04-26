#include <iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildtree(Node* root) {
    cout << "Enter the data (-1 for no node): " << endl;
    int data;
    cin >> data;

    // if input is -1, return nullptr immediately (base case)
    if (data == -1) {
        return nullptr;
    }
    
    root = new Node(data);
    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void inordertraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
}

void preordertraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}

void postordertraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout << root->data << " ";
}

// void levelordertraversal(Node* root){
//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()){
//         Node* temp=q.front();
//         q.pop();

//         cout<<temp->data<<" ";
//         if(temp->left){
//             q.push(temp->left);
//         }
//         if(temp->right){
//             q.push(temp->right);
//         }
//     }
// }

void levelordertraversal(Node* root) {
    if (root == nullptr) return; // Handle empty tree case

    queue<Node*> q;
    q.push(root);
    q.push(nullptr); // Marker for a new level

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr) { // End of the current level
            cout << endl;
            if (!q.empty()) {
                q.push(nullptr); // Add a new level marker
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

void buildfromlevelorder(Node*& root) {
    queue<Node*> q;
    cout << "Enter the data for the root: ";
    int data;
    cin >> data;

    if (data == -1) return;  // If root data is -1, return an empty tree

    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        cout << "Enter left node for " << front->data << " (-1 for no node): ";
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1) {
            front->left = new Node(leftdata);
            q.push(front->left);
        }

        cout << "Enter right node for " << front->data << " (-1 for no node): ";
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1) {
            front->right = new Node(rightdata);
            q.push(front->right);
        }
    }
}

int main() {
    Node* root = nullptr;
    // root = buildtree(root);
    buildfromlevelorder(root);

    cout << "\nInorder Traversal: ";
    inordertraversal(root);
    
    // cout << "\nPreorder Traversal: ";
    // preordertraversal(root);
    
    // cout << "\nPostorder Traversal: ";
    // postordertraversal(root);

    cout<<"\nleveloredertraversal: ";
    levelordertraversal(root);
    
    return 0;
}
