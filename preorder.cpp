class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorderHelper(root, res);
        return res;
    }
    
    void preorderHelper(Node* root, vector<int>& res) {
        if(!root) return;
        res.push_back(root->val);
        for(int i = 0; i < root->children.size(); i++) {
            preorderHelper(root->children[i], res);
        }
        return;
    }
};
