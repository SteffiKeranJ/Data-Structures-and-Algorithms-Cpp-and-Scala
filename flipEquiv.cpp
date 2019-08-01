class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if (root1== NULL  && root2== NULL) 
            return true; //true if both the nodes are null
        
         if (root1 == NULL || root2 == NULL || root1->val != root2->val) 
            return false; // if just one node is null and the value is also mismatching
        
        // this you will do for left to right of root1 and root2
        // or left to left of root1 and root2
        return (root1->val == root2->val) && (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))|| (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));

    }
    
};
