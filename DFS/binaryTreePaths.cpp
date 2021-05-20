class Solution {
public:
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, to_string(root->val));
        return ans;
    }
    
    void dfs(TreeNode* root, string s) {
        if(!root->left && !root->right) {
            ans.push_back(s);
            return;
        }
        if(root->left) dfs(root->left, s+"->"+to_string(root->left->val));
        if(root->right) dfs(root->right, s+"->"+to_string(root->right->val));
    }
};
