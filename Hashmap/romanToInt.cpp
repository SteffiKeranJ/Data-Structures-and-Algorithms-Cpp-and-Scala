class Solution {
public:
    map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int n = s.size();
        int sum = romanMap[s[n-1]];
        int temp;
        for(int j = n-2; j >=0;--j) {
            if(romanMap[s[j]]< romanMap[s[j+1]]) sum-=romanMap[s[j]];
            else sum+=romanMap[s[j]];
        }
        return sum;
    }
};
