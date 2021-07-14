/**
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
**/

class Solution {
public:    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* dummy = head;
        int k = lists.size();
        struct compare {
            bool operator() (ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };
                
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i = 0; i < k; ++i) {
             if(lists[i]) pq.push(lists[i]);
        }
         if (pq.empty())  return NULL;
        while(!pq.empty()) {
            ListNode* top = pq.top();
            dummy->next = top;
            dummy = dummy->next;
            pq.pop();
            if(top->next) pq.push(top->next);
        }     
        
        return head->next;
    }
};
