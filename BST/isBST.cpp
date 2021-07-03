/** 
Given a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
**/
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBSThelper(Node* root, Node* left, Node* right) {
        
        if(!root) return true;
        if(left && root->data <= left->data ) return false;
        if(right && root->data >= right->data) return false;

        return isBSThelper(root->left, left, root) && isBSThelper(root->right, root, right);
    }
    
    bool isBST(Node* root) 
    {
       return isBSThelper(root, NULL, NULL);
    }
};

