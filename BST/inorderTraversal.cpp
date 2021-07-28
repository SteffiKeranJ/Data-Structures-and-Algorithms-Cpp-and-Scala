class Solution {
public:
    vector<int> nodes;
    void inorderTraversal(TreeNode* root) {
        if(!root) return;
        if(root->left) inorderTraversal(root->left);
        nodes.push_back(root->val);
        if(root->right) inorderTraversal(root->right);
    }
    
    TreeNode* constructBST(int low, int high)  {
        if(low > high) return NULL;
        int mid = low + (high - low)/2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = constructBST(low, mid-1);
        node->right = constructBST(mid+1, high);
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        inorderTraversal(root);
        int n = nodes.size();
        return constructBST(0, n-1);
    }
};
