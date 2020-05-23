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
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        queue<int> level;
        while(!q.empty()) {
            int max = -2147483648;
            int s = q.size();
            for(int i = 0; i < s; ++i) {
                TreeNode* temp = q.front();
                // pop it
                max = max > temp->val ? max : temp->val;
                q.pop();
                if (temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            res.push_back(max);
        }
        return res;
    }
};
