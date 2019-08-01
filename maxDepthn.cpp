class Solution {
public:
    int maxDepth(Node* root) {
        if (root==NULL) return 0;
        int maxl = 1;
        for(int i = 0; i < root->children.size(); i++) {
            if(root->children[i]) {
                maxl = max(maxl, 1+ maxDepth(root->children[i]));
            }
        }
        return maxl;
    }
};
