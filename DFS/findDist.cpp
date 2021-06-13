class Solution {
public:
Node* LCA(Node* root, int a, int b)    {
    if(!root) return NULL;
    if(root->data == a || root->data ==b) return root;
    Node* left = LCA(root->left, a, b);
    Node* right = LCA(root->right, a, b);
    if(left and right) return root;
    if(left) return left;
    return right;
}

int findDistance(Node* root, int x) {
    if(!root) return 0;
    if(root->data == x) return 1;
    int left = findDist(root->left, x);
    int right = findDist(root->right, x);
    if(!left and !right) return 0;
    return left + right + 1;
}


int findDist(Node* root, int a, int b) {
    if(!root) return 0;
    Node* lca = LCA(root, a, b);
    int da = findDistance(lca, a);
    int db = findDistance(lca, b);
    return da+db -2;
}

}
