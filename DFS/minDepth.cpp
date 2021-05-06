class Solution {
public:  
    int min(int a, int b) {
        return a < b ? a:b;
    }
    
    int minDepth(TreeNode* root) {
        if(!root)  return 0;
        if(!root->left && !root->right) return 1;
        
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        
        if(!root->left) return 1+right;
        
        if(!root->right) return 1+left;
        
        root->left=NULL;
        
        return min(left, right)+1;
        
    }
};
