class Solution {
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        findMax(root);
        return res;
    }
    
private: 
    int findMax(TreeNode* root) {
        if (root == NULL) return 0;
        int left = max(0, findMax(root->left));
        int right = max(0, findMax(root->right));
        res = max(res, left+right+root->val);
        return max(left, right) + root->val;
    }
};
