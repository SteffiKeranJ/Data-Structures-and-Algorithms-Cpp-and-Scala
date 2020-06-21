class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int count = 0;        
        int sum=0;
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            sum+=nums[i];
            int rem = sum-k;
            if(map.count(rem)) {
                count+=map[rem];
            }
            map[sum]++;
        }
        return count;
    }
};
auto ii = [](){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();
