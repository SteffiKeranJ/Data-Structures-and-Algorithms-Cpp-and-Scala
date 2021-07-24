class Solution {
private:
    int res;
public:
    void helper(TreeNode* root, int &k) {
        if(!root) return;
        helper(root->right, k);
        if(--k == 0) res = root->val;
        helper(root->left, k);
    }
    
    int kthLargestRecursive(TreeNode* root, int k) {
        helper(root, k);

        return res;
    }
};
