class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* head = l3;
        int sum, x, y;
        int carry = 0;
        if (l1==NULL && l2 == NULL) { // check if any ll is null
            ListNode* nullList = new ListNode(0);
            return nullList;
        }
        while(l1!=NULL || l2!=NULL) {
            x = (l1 == NULL) ? 0 : l1->val;
            y = (l2==NULL)?0:l2->val;
            sum = carry + x + y; 
            carry = sum/10;
            l3->next = new ListNode(sum%10);
            l3 = l3->next;
            if (l1!=NULL) l1 = l1->next;
            if (l2!=NULL) l2 = l2->next;
        }
        // if a carry is remaining
        if (carry > 0) {
            l3->next = new ListNode(carry);
        }
        return head->next;
    }
};
