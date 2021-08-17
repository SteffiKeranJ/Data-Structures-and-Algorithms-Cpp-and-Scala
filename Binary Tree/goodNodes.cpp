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
    int helper(TreeNode* root, int maxVal) {
        if(!root) return 0;
        int count = 0;
        if(root->val >= maxVal) count++;
        maxVal = max(root->val, maxVal);
        return count + helper(root->left, maxVal) + helper(root->right, maxVal);
    }
    
    
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};
