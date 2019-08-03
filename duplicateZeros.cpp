class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int s = arr.size();
        int i;
        for(i = 0; i < s;i++) {
            if(arr[i]==0){
                arr.insert(arr.begin()+i, 0);
                arr.pop_back();
                i++;
            }
        }
        return;
    }
};
