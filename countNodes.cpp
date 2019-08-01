class Solution {
public:
    int res = 0;
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        res++;
        countNodes(root->left);
        countNodes(root->right);
        return res;
        
    }
};
