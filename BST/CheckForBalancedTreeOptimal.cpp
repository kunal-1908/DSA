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
pair<bool,int> isbalanced(node* root) {
    if (root == NULL) {
        return make_pair(true, 0); 
    }
    
    pair<bool,int> left = isbalanced(root->left);
    pair<bool,int> right = isbalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff) {
        ans.first = true;
    } else {
        ans.first = false;
    }
    return ans;
}

bool solve(node* root) {
    return isbalanced(root).first;
}
int main() {
    node *root = NULL;

    root = buildtree(root);
    cout<<"levelordertraversal: ";
    levelordertraversal(root);

    bool isbalanced=solve(root);
    return 0;
}
