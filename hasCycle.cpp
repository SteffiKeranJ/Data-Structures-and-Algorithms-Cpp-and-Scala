// uses slow and fast pointer
// if there is a cycle, the slow and fast pointer will meet at some point of time and we return true
// else, the while loop will break at the end of the dead end of the list and we return false
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* slow =  head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
