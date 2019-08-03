class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return new ListNode(0);
        if(!l1) return l2;
        if(!l2) return l1;
        stack<int> l1q;
        stack<int> l2q;
        stack<int> l3q;
        ListNode* l3 = new ListNode(0);
        ListNode* head = l3;
        int sum, x, y, temp;
        int carry =0;
        while(l1 || l2) {
            if(l1) {
                l1q.push(l1->val);
                l1 = l1->next;
            }
            if(l2) {
                l2q.push(l2->val);
                l2 = l2->next;
            }
        }
        while(!l1q.empty() || !l2q.empty()) {
            if(l1q.empty()) x = 0;
            else {
                x = l1q.top();
                l1q.pop();
            }
            if(l2q.empty()) y =0;
            else{
                y = l2q.top();
                l2q.pop();
            }
            sum = x+y+carry;
            carry = sum/10;
            l3q.push(sum%10);
        }
          if (carry > 0) {
           l3q.push(carry);
        }
        while(!l3q.empty()) {
            temp = l3q.top();
            l3q.pop();
            l3->next = new ListNode(temp);
            l3 = l3->next;
        }
        return head->next;
    }
};
