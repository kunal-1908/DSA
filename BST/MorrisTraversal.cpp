TreeNode *find(TreeNode *curr){
    TreeNode *pred=curr->left;
    while(pred->right!=nullptr && pred->right!=curr){
        pred=pred->right;
    }
    return pred;
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }

    TreeNode *curr=root;
    while(curr!=nullptr){
        if(!curr->left){
            ans.push_back(curr->data);
            curr=curr->right;
        }
        else{
            TreeNode *pred=find(curr);
            if(pred->right==nullptr){
                pred->right=curr;
                curr=curr->left;
            }else{
                pred->right=nullptr;
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return ans;
}