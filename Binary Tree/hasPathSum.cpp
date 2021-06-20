class Solution
{
    public:
    bool hasPathSum(Node *root, int S) {
    if(!root) return false;
    int newSum = S-root->data;
    if(!root->left && !root->right) return newSum==0;
    
    return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);
}
};
