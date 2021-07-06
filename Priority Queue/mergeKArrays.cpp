/** 
Merge K sorted Arrays
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].
**/

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res;
        using arrayNode= array<int, 3>;
        priority_queue<arrayNode, vector<arrayNode>, greater<arrayNode>> pq;
        int i, j;
        for(i = 0; i < K; ++i) {
            pq.push({arr[i][0], i, 0});
        }
        while(!pq.empty()) {
            int arrValue = pq.top()[0];
            int arrRow = pq.top()[1];
            int arrIndex = pq.top()[2];
            pq.pop();
            res.push_back(arrValue);
            if(arrIndex+1 < K) {
                pq.push({arr[arrRow][arrIndex+1], arrRow, arrIndex+1});
            }
        }
        return res;
    }
};
