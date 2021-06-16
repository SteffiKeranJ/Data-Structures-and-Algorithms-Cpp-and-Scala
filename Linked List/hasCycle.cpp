class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        unordered_map<ListNode*, int> m;
        while(head) {
            if(!m[head]){
                m[head]= 1;
                head = head->next;
            } else {
                return true;
            }
        }
        return false;        
    }
};
