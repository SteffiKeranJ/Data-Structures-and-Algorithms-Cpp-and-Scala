class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
       stack<TreeNode*> numberStack;
        numberStack.push(root); 
        while(!numberStack.empty() || root) {
            while(root) {
                numberStack.push(root); 
                root= root->right; 
            }
            root=numberStack.top(); 
            numberStack.pop();
            if(--k == 0) return root->val; 
            root = root->left;            
        }
        
        return -1;
    }
};
