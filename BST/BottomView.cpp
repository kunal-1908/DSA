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
vector<int> BottomView(node* root) {
    map<int, int> topnodes;
    queue<pair<node*, int>> q;
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second;

        // Update the map without checking, as we need the bottom-most node at each hd
        topnodes[hd] = frontnode->data;

        if (frontnode->left) {
            q.push(make_pair(frontnode->left, hd - 1));
        }

        if (frontnode->right) {
            q.push(make_pair(frontnode->right, hd + 1));
        }
    }

    for (auto i : topnodes) {
        ans.push_back(i.second);
    }

    return ans;
}
int main() {
    node *root = NULL;

    root = buildtree(root);
    cout<<"BottomView:"<<endl;
    vector<int> ans=BottomView(root);
    return 0;
}
