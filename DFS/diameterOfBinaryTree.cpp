class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res - 1;
    }
    
    int dfs(TreeNode* root){
        if(!root) return 0;
        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);
        res = max(res, leftDepth+rightDepth+1);
        return max(leftDepth, rightDepth)+1;
    }
    
    int max(int a, int b) {
        return a>b ? a:b;
    }
    
    int res = 0;
};
