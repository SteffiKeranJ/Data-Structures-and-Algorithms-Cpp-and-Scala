class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& res) {
        if(!root) return; 
        if(!root->left && root->right) res.push_back(root->right->val);
        if(!root->right && root->left) res.push_back(root->left->val);
        dfs(root->left, res);
        dfs(root->right, res);
    }
};
