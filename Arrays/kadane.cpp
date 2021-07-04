/**
Kadane's algorithm

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

**/

int maxSubarraySum(int arr[], int n){
        
        int maxSum = arr[0];
        int currentMaxSum = arr[0];
        for(int i = 1; i < n; ++i) {
            currentMaxSum = max(currentMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currentMaxSum);
        }
        return maxSum;
    }
