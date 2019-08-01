class Solution {
public:
    ListNode* plusOneLinkedList(ListNode* head) {
        if(!head) return NULL;
        if(helper(head)!=0) {
            ListNode* newnode = new ListNode(1); // create a new node
            newnode->next = head;
            head = newnode;
        }
        return head;
    }
    
    int helper(ListNode* node){
        int carry = node->next ? helper(node->next) : 1;
        int sum = node->val+carry;
        node->val = sum%10; // do not store the carry in the node
        return sum/10;
    }
};
