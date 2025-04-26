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
void solve(node* root, int len, int &maxlen, int sum, int &maxsum) {
    if (root == NULL) {
        if (len > maxlen) {
            maxlen = len;
            maxsum = sum;
        }
        else if (len == maxlen) {
            maxsum = max(sum, maxsum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, len + 1, maxlen, sum, maxsum);
    solve(root->right, len + 1, maxlen, sum, maxsum);
}

int sumoflongestbloodline(node* root) {
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxsum = INT16_MIN;

    solve(root, len, maxlen, sum, maxsum);
    return maxsum;
}
int main() {
    node *root = NULL;

    root = buildtree(root);
    cout<<"sum of longest bloodline is:"<<sumoflongestbloodline(root)<<endl;
    return 0;
}
