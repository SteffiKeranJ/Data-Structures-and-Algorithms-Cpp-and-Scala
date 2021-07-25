/** 

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed. 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
**/


class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp) {
            st.push(temp);
            temp = temp->next;
        }
        ListNode* cur = head;
        
        ListNode* next;
        ListNode* endNode;
        
        while(cur) {
            endNode = st.top();
            st.pop();
            
            next = cur->next;
            cur->next = endNode;
            endNode->next = next;
            cur = next;            
            if(cur and cur->next == endNode) {
                cur->next = NULL;
                break;
            }
        }
    }
};
