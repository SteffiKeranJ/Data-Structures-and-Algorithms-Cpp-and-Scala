class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return root;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        return root;
    }
};
