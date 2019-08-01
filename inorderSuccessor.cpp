class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL; // if root is null return null
        if (root->val <= p->val) { // traverse right for a bigger value 
            root = inorderSuccessor(root->right, p); 
        }
        else { // else traverse left 
          TreeNode* left = inorderSuccessor(root->left, p);
            root = (left ? left : root);                  
        }
        return root;
      
    }
};
