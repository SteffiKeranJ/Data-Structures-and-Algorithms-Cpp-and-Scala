class Solution {
public:
    int trap(vector<int>& height) {
       int n =  height.size();
        int water = 0;
        int lo  = 0;
        int hi = n-1;
        
        int minh = 0;
        int maxh = 0;
        while(lo <= hi) {
            if(height[lo] < height[hi]) {
                if(height[lo] >minh) {
                    minh = height[lo];
                } else {
                    water+= minh - height[lo];
                }
                lo++;
            }else {
                if(height[hi] > maxh) {
                    maxh = height[hi];
                }else {
                    water+= maxh - height[hi];
                }
                hi--;
            }
        }
        
        return water;
        
    }
};
