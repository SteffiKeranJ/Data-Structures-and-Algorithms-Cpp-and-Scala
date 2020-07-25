class Solution {
public:
    int res = 0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    int abs(int a, int b) {
        return a > b ? a-b : b-a;    
    }
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        res += abs(left, right);
        return left + right + root->val;
    }
};
