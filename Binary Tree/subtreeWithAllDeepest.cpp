class Solution {
public:
    pair<int, TreeNode*>findDeep(TreeNode* root) {
        if(!root) return {0, NULL};
        
        pair<int, TreeNode*> left = findDeep(root->left),
                            right = findDeep(root->right);
        
        int depth1 = left.first;
        int depth2 = right.first;
        
        return {max(depth1, depth2)+1, depth1==depth2 ? root : depth1 > depth2 ? left.second: right.second};
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return findDeep(root).second;
    }
};
