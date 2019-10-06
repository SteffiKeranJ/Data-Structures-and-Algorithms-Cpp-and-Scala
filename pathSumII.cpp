/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void pathSumhelper(TreeNode* root, int sum, vector<vector<int>>&res, vector<int>&path){
        if(root==NULL) return;
        path.push_back(root->val);
        if(!(root->left) && !(root->right) && sum == root->val)
            res.push_back(path);
        pathSumhelper(root->left, sum-root->val, res, path);
        pathSumhelper(root->right, sum-root->val, res, path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        pathSumhelper(root, sum, res, path);
        return res;
    }
};
