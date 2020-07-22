class Solution {
public:
	int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
		int maxSoFar=nums[0], minSoFar=nums[0],res=nums[0];
		for(int i=1;i<nums.size();++i){
			int temp1=maxSoFar, temp2=minSoFar;
			maxSoFar=max(temp2*nums[i],max(temp1*nums[i],nums[i]));
			minSoFar=min(temp2*nums[i],min(temp1*nums[i],nums[i]));
			res=max(res,maxSoFar);
		}

		return res;
	}
};
