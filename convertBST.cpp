class Solution {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        if(root->right) convertBST(root->right);
        root->val = (sum+=root->val);
        if(root->left) convertBST(root->left);
        return root;
    }
};
