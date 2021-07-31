class Solution {
public:
    int count = 0;
    void dfs(TreeNode* root, int maxValueSeen) {
        if(root->val >= maxValueSeen) count++;
        maxValueSeen = max(maxValueSeen, root->val);
        if(root->left) dfs(root->left, maxValueSeen);
        if(root->right) dfs(root->right, maxValueSeen);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};
