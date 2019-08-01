class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderHelper(root, res);
        return res;
    }
    
    void postorderHelper(TreeNode* root, vector<int>& res) {
        if(!root) return;
        postorderHelper(root->left, res);
        postorderHelper(root->right, res);
        res.push_back(root->val);
    }
};
