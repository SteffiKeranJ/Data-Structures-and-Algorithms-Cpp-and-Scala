class Twitter {
private:
    unordered_map<int, unordered_set<int>> friends;
    int timeStamp;
    priority_queue<vector<int>>timeline;
public:
    Twitter() {
        friends.clear();
        timeStamp = 0;
        timeline = priority_queue<vector<int>>();
        
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({timeStamp++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        priority_queue<vector<int>> userTimeline = timeline;
        int n = 0;
        while(!userTimeline.empty() and n < 10) {
            vector<int> topfeed = userTimeline.top();
            if(topfeed[2] == userId || friends[userId].find(topfeed[2])!=friends[userId].end()){
                res.push_back(topfeed[1]);
                n++;
            }
            userTimeline.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
