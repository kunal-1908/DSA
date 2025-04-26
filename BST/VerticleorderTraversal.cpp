#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
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
vector<int> verticalordertraversal(node* root){
    map<int,map<int,vector<int> > > nodes;
    queue<pair<node*,pair<int,int>>> q;
    vector<int> ans;

    if(root==NULL){
        return ans;
    }
    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<node*,pair<int,int>> temp=q.front();
        q.pop();

        node* frontnode=temp.first;
        int hd=temp.second.first;
        int level=temp.second.second;

        nodes[hd][level].push_back(frontnode->data);

        if(frontnode->left){
            q.push(make_pair(frontnode->left,make_pair(hd-1,level+1)));
        }
        else{
            q.push(make_pair(frontnode->right,make_pair(hd+1,level+1)));
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main() {
    node *root = NULL;

    root = buildtree(root);
    cout<<"verticalordertraversal:"<<endl;
    vector<int> ans=verticalordertraversal(root);
    return 0;
}
