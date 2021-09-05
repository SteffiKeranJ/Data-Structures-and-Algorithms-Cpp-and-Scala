/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        if(!root->left) return;
        TreeNode* left = root->left;
        TreeNode* t = left;
        while(t->right!=NULL) {
            t = t->right;
        }
        t->right = root->right;
        root->right = left;
        root->left = NULL;
    }
    
    void flatten(TreeNode* root) {
        dfs(root);
    }
};
