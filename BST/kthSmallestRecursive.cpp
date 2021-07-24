class Solution {
private:
    int res;
public:
    void helper(TreeNode* root, int &k) {
        if(!root) return;
        helper(root->left, k);
        if(--k == 0) res = root->val;
        helper(root->right, k);
    }
    
    int kthSmallestRecursive(TreeNode* root, int k) {
        helper(root, k);

        return res;
    }
};
