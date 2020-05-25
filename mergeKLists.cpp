/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> freq;
        for(int i = 0 ; i < lists.size(); ++i) {
            auto node = lists[i]; // take the head
            while(node) {
                // take the node's val
                int temp = node ->val;
                // put it in the ordered map
                freq[temp]++;
                node = node->next;
            }
        }
        ListNode dummy(0); // create new linked list
        ListNode* tail = &dummy;
        for(auto i : freq) {
            while(i.second!=0) {
                // create a node for every item
                ListNode* newnode = new ListNode(i.first);
                // add it to tail
                tail->next = newnode;
                tail = tail->next;
                // decrement the freq
                i.second--;
            }
        }
        return dummy.next;
    }
};
