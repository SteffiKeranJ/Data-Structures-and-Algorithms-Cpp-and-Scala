class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxA = INT_MIN;
        while(left <= right) {
            int minHeight = min(height[right], height[left]);
            maxA = max(maxA, minHeight*(right-left));
            if(height[right] <= height[left]) right--;
            else left++;
        }
        return maxA;
    }
};
