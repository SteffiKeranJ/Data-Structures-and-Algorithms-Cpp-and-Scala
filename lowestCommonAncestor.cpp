TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root) return NULL;
      if (root == p || root ==q) return root;
      else {
          TreeNode* left = lowestCommonAncestor(root->left, p, q);
          TreeNode* right = lowestCommonAncestor(root->right, p, q);
          return left != NULL && right != NULL ? root : left == NULL ? right : left; 
      }
  }
