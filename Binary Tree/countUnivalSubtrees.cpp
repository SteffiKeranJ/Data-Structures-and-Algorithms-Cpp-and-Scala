class Solution {
public:
     bool isUnival(TreeNode* root) {
        if (!root) return true;
        if (root->left) {
            if (!(isUnival(root->left) and root->val == root->left->val)) {
                return false;
            }
        }
        if (root->right) {
            if (!(isUnival(root->right) and root->val == root->right->val)) {
                return false;
            }
        }
        return true;
    }
    
    
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        else return countUnivalSubtrees(root->left) 
            + countUnivalSubtrees(root->right) 
            + isUnival(root);
    }
};
