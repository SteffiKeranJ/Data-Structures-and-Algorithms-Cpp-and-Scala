class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorderHelper(root, res);
        return res;
    }
    
    void postorderHelper(Node* root, vector<int>& res) {
        if(!root) return;
        int i;
        for(i = 0; i < root->children.size();i++) {
            postorderHelper(root->children[i], res);
        }
        res.push_back(root->val);
    }
};
