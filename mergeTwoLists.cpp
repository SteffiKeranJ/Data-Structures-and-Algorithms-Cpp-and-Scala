class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* head = l3;
        if (l1 == NULL && l2 == NULL ){
             ListNode* null_list(NULL);
            return null_list;    
        } 
        while(l1!=NULL && l2!=NULL) {
            if(l1->val <= l2->val) {
            l3->next = new ListNode(l1->val);
            l1 = l1->next;
            } else {
                l3->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        while (l2!=NULL) {
            l3->next = new ListNode(l2->val);
            l2 = l2->next;
            l3 = l3->next;
        }
        while(l1!=NULL) {
            l3->next = new ListNode(l1->val);
            l1 = l1->next;
            l3 = l3->next;
        }
        return head->next;
    }
};
