class Solution {
public:
    int diameter(Node* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }
    
    int dfs(Node* root){
        if(!root) return 0;
        int max1 = 0;
        int max2 = 0;
        int i = 0;
        for(; i < root->children.size();++i){
            int p = dfs(root->children[i]);
            if(p > max1) {
                max2 = max1;
                max1 = p;
            } else if (p > max2) {
                max2 = p;
            }
        }
        res = max(res,  max1 + max2);
        return 1+max1;
    }
    int max(int a, int b) {
        return a > b ? a:b;
    }
    int res = 0;
};
