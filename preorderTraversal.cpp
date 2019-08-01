class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& res) {
        if(root) {
            res.push_back(root->val);
            if(root->left) helper(root->left, res);
            if(root->right) helper(root->right, res);
        }
    }
};
