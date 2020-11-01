class Solution {
    struct comparator {
    bool operator()(pair<int, int>a, pair<int, int>b) {
        int x1 = a.first * a.first;
        int y1 = a.second * a.second;
        int x2 = b.first * b.first;
        int y2 = b.second * b.second;
        return (x1 + y1) > (x2 + y2); 
    }
};
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        if(points.size()==0)return res;
        priority_queue<pair<int,int>, vector<pair<int, int>>, comparator> pq;
        for(int i = 0; i < points.size(); ++i) {
            pq.push(make_pair(points[i][0], points[i][1]));
        }
        pair<int, int> ptr;
       
        while(K-- > 0 && !pq.empty()) {
            ptr = pq.top();
            printf("%d %d", ptr.first, ptr.second);
            res.push_back({ptr.first, ptr.second});
            pq.pop();
           
        }
        return res;
    }
};
