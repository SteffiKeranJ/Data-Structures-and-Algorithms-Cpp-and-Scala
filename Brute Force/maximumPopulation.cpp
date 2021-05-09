class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int max_count = 0;
        int arr[101]={0};
        int n = logs.size();
        int count = 0;
        int res_year;
        int i;
        
        for(i = 0; i < n; ++i) {
            arr[logs[i][0] - 1950]+=1;
            arr[logs[i][1] - 1950]-=1;
        }
        
        for( i = 0; i < 101; ++i) {
            count+=arr[i];
            if(count > max_count) {
                max_count = count;
                res_year = i + 1950;
            }
        }
        
        return res_year;
    }
};
