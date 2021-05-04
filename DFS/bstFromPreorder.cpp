class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(!n) return new TreeNode();
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* head = root; 
        stack<TreeNode*> s;
        int i = 1;
        while(i < n) {
            if(preorder[i] <  head->val) {
                head->left  = new TreeNode(preorder[i]);
                s.push(head);
                head = head->left;
            } else {
                while(!s.empty() && s.top()->val < preorder[i]) {
                    head = s.top();
                    s.pop();
                }
                head->right = new TreeNode(preorder[i]);
                head = head->right;
            }
            ++i;
        }
        
        
        
        return root;
    }
};
