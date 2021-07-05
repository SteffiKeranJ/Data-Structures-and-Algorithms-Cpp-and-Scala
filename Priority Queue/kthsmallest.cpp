/** 

Find the kth smallest element in an unsorted array of non-negative integers.

Definition of kth smallest element

kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.

In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based )

NOTE

You are not allowed to modify the array ( The array is read only ). 

Try to do it using constant extra space.

Example:

A : [2 1 4 3 2]
k : 3

answer : 2
**/

int Solution::kthsmallest(const vector<int> &A, int B) {
        int n  = A.size();
        priority_queue<int> pq;
        for(int i = 0; i < B; ++i) {
            pq.push(A[i]);
            if(pq.size() > B) pq.pop();
        }
        for(int i = B; i < n; ++i) {
            if(pq.top() > A[i]) {
                pq.pop();
                pq.push(A[i]);
            }
        }
        if(!pq.empty()) return pq.top();
        return -1;
}
