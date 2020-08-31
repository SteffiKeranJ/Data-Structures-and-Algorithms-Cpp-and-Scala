class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int i = 0;
        int A = 0;
        int B = 0;
        int count[10] = {0};

        int n = secret.size();
        vector<pair<int,int>> map;
        for(; i < n; ++i) {
            if(secret[i]==guess[i]) A++;
            else {
                if(count[secret[i]-'0'] < 0) B++;
                    count[secret[i]-'0']++;

                if(count[guess[i]-'0'] > 0) B++;
                    count[guess[i]-'0']--;
            }
        }
        res = to_string(A)+"A"+to_string(B)+"B";
        return res;
        
    }
};
