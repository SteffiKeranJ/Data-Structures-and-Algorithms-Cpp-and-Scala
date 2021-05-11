class Solution {
public:
    int h;
    int ans = 0;
    int max(int a, int b) {
        return a > b ? a:b;
    }
    int deepestLeavesSum(TreeNode* root) {
        // traverse for height
        int h = height(root);
        // traverse again to find the deepest  leaves sum
        return deepSum(root, h);
    }
    
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    int deepSum(TreeNode* root,int h){
        if(!root) return 0;
        if(h==1) return root->val;
        else return deepSum(root->left, h-1)+
        deepSum(root->right, h-1);
    }
};
