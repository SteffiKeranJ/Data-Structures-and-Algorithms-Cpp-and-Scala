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
private:
    vector<int> bstArray;
public:
    void helper(TreeNode* root) {
        if(!root) return;
        helper(root->left);
        bstArray.push_back(root->val);
        helper(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        int left = 0;
        int right = bstArray.size()-1;
        while(left < right) {
            int sum = bstArray[left] + bstArray[right];
            if(sum == k) return true;
            if(sum < k) left++;
            else right--;
        }
        
        return false;
        
    }
};
