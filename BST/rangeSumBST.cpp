/** 
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

**/

class Solution {
public:   
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int rootVal = root->val >= low && root->val <= high ? root->val:0;
        if(!root->left && !root->right) 
            return rootVal;
        
        if(!root->right) return rootVal + rangeSumBST(root->left, low, high );
        if(!root->left) return rootVal + rangeSumBST(root->right, low, high );
        return rootVal + rangeSumBST(root->left, low, high) +rangeSumBST(root->right, low, high) ;
    }
};
