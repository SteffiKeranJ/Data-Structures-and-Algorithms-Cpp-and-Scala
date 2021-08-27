class Solution {
public:
    int helper(TreeNode* node, int curMax, int curMin) {
        if(!node) return curMax-curMin;
        curMax = max(node->val, curMax);
        curMin = min(node->val, curMin);
        return max(helper(node->left, curMax, curMin), helper(node->right, curMax, curMin));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        return helper(root, root->val, root->val);
    }
};
