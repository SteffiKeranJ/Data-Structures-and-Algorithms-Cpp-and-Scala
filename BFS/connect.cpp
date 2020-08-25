class Solution {
public:
    Node* connect(Node* root) {
       Node* leftNode = root;
        while(leftNode && leftNode->left) { // there s a level below
            getNextLevelDown(leftNode);
            leftNode = leftNode->left;
        }
        return root;
    }
    
    void getNextLevelDown(Node* node) {
        Node* ptr = node;
        while(ptr) {
            //point from left to right
            ptr->left->next = ptr->right;
            if(ptr->next) {
                ptr->right->next = ptr->next->left;
            }
            ptr = ptr->next;
        }
    }
};
