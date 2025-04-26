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
void solve(node* root, int &count, vector<int> &path, int k) {  // Pass path by reference
    if(root == NULL) {
        return;
    }
    path.push_back(root->data);

    solve(root->left, count, path, k);
    solve(root->right, count, path, k);

    int size = path.size();
    int sum = 0;
    for(int i = size - 1; i >= 0; i--) {
        sum += path[i];
        if(sum == k) {
            count++;
        }
    }
    path.pop_back();
}

int kpathsum(node* root, int k) {
    int count = 0;
    vector<int> path;
    solve(root, count, path, k);
    return count;
}

int main() {
     // 2 3 10 -1 -1 11 -1 -1 5 4 -1 -1 6 9 -1 -1 -1
    node *root = NULL;
    root = buildtree(root);
    int k=5;

    int ans=kpathsum(root,k);
    cout<<"total no of such path is:"<<ans<<endl;
    return 0;
}
