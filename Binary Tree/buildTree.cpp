/** 
105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
**/




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
    unordered_map<int, int> inorderMap;
    int preorderCount;
    
    TreeNode* buildTree(vector<int>& preorder, int left, int right) {
        if(left > right) return NULL;
        int rootVal = preorder[preorderCount++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(preorder, left, inorderMap[rootVal]-1);
        root->right = buildTree(preorder, inorderMap[rootVal] + 1, right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderCount = 0;
        inorderMap = unordered_map<int,int>();
        for(int i =0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i; // find the position of root in constant time
        }
        return buildTree(preorder, 0, preorder.size()-1);
        
    }
};
