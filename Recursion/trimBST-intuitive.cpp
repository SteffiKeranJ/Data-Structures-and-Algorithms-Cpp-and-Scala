class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        if(root->val < low) {
            return root->right;
        }else if(root->val > high) {
            return root->left;
        }
        return root;
    }
};
