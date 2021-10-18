class Solution {
private:
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        findMaxPath(root);
        return res;        
    }
    
    int findMaxPath(TreeNode* root) {
        if(!root) return 0;
        int left = max(0, findMaxPath(root->left));
        int right = max(0, findMaxPath(root->right));
        res = max(res, left+right+root->val);
        return max(left, right) + root->val;
        
    }
};
