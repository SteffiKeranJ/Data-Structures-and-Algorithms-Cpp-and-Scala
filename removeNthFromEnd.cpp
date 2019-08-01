class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        int c2;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        temp = head;
        if (n >= count) {
            head = head->next;
        } else {
            for(c2 = 1;c2 <count-n; c2++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        }
        
    return head;
    }
};
