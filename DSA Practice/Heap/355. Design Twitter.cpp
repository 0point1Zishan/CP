class Twitter {
public:
    unordered_map<int, list<pair<int, int>> > t;
    unordered_map<int, set<int>> followers;
    int time = 0;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_front({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> mxHeap;
        for(auto val: t[userId])  mxHeap.push(val);

        for(auto f: followers[userId]){
            for(auto it: t[f])  mxHeap.push(it);
        }
        vector<int> v;
        int cnt = 10;
        while(!mxHeap.empty() && cnt--){
            v.push_back(mxHeap.top().second);
            mxHeap.pop();
        }
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */