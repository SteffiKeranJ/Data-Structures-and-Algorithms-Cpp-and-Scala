class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       stack<TreeNode*> numberStack;
        numberStack.push(root); 
        while(!numberStack.empty() || root) {
            while(root) {
                numberStack.push(root); 
                root= root->left; 
            }
            root=numberStack.top(); 
            numberStack.pop();
            if(--k == 0) return root->val; 
            root = root->right;            
        }
        
        return -1;
    }
};
