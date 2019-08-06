class Solution {
public:
    bool isArmstrong(int N) {
        vector<int> v;
        int n = N;
        while(n > 0) {
            v.push_back(n%10);
            n = n/10;
        }
        int k = v.size();
        n = N;
        int sum = 0;
        while(n > 0) {
            int temp = 1;
            int modl = n%10;
            while(k> 0) {
                temp *= modl;
                k--;
            }
            sum+=temp;
            k = v.size();
            n = n/10;
        }        
        return sum == N;
    }
};
