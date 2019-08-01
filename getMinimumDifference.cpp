class Solution {
private:
    int diff = INT_MAX;
    int minimum = -1;    
public:
    int getMinimumDifference(TreeNode* root) {
        if(root->left) getMinimumDifference(root->left);
        if(minimum >=0) diff = min(diff, (root->val - minimum));
        minimum = root->val;
        if(root->right) getMinimumDifference(root->right);
        return diff;
    }
  
};
