/** 
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.

TIP: C users, please malloc the result into a new array and return the result.

If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]

**/


void Solution::merge(vector<int> &A, vector<int> &B) {
	int n = A.size()-1;
	int m = B.size()-1;
    A.resize(A.size()+B.size());
	int res_length = n+m+1;
    while(n >=0 && m >=0) {
		A[res_length--] = A[n] > B[m] ? A[n--] : B [m--];
	}
	while(m >= 0)
		A[res_length--] = B[m--];
}
