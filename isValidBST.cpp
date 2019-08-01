class Solution {

public:
    bool isValidBST(TreeNode* root) {
       return checkIsBst(root, NULL, NULL);
    }
    
    bool checkIsBst(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(root == NULL) return true;
        if ((min && root->val <=  min->val) || (max&&root->val >= max->val)) return false;
        return checkIsBst(root->left, min, root) && checkIsBst(root->right, root, max);
    }
};
