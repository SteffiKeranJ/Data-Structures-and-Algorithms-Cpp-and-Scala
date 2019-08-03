// since it is a sorted list, no need to maintain any hash set
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* temp = head;
        while(temp && temp->next){
            if(temp->val != temp->next->val) {
                temp = temp->next;
            } else {
                if(temp->next->next) {
                    temp->next = temp->next->next;  
                }
                 else{
                    temp->next = NULL;
                    break;
                } 
            }
        }
        return head;
    }
};
