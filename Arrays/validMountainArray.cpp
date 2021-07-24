/**

941. Valid Mountain Array

Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true
**/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int maxVal = arr[0];
        int maxIndex = 0;
        int n = arr.size();
        for(int i =1; i < n; ++i){
            if(arr[i] == arr[i-1]) return false;
            if(arr[i] > maxVal) {
                maxVal = arr[i];
                maxIndex = i;
            }
        }
        if(maxIndex == 0 || maxIndex == n-1) return false;
         for(int i = 0; i < maxIndex; ++i) {
            if(arr[i] > arr[i+1] ) return false;
        }
        for(int i = maxIndex+1; i < arr.size(); ++i) {
            if(arr[i] > arr[i-1] ) return false;
        }
        return true;
    }
};
