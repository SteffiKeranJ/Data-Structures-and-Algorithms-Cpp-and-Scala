class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        helper(root, res); // for recursive, no need to put the base condition in the main
       return res;
    }
    
    void helper(TreeNode* root, vector<int>& res) {
         if(root) {
            if(root->left) helper(root->left, res);
             res.push_back(root->val);
            if(root->right) helper(root->right, res);
            
        }
    }
};
