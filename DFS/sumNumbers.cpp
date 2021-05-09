class Solution {
public:
    int sum = 0;
    
    int dfs(TreeNode* root, stack<int> st) {
        if(!root) return 0;
        st.push(root->val);
        if(!root->left && !root->right) {
            int i = 0;
            while(!st.empty()) {
                sum +=  st.top()*pow(10, i);
                st.pop();
                ++i;
            }
        }
        if(root->left) dfs(root->left, st);
        if(root->right) dfs(root->right, st);
        return sum;
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        stack<int> st;
        return  dfs(root, st);
    }
};
