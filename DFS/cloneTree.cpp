class Solution {
public:
    Node* cloneTree(Node* root) {
        if(!root) return root;
        Node* tmp = new Node(root->val);
        for(int i = 0; i < root->children.size(); ++i){
            tmp->children.push_back(cloneTree(root->children[i]));
        }
        return tmp;
    }
};
