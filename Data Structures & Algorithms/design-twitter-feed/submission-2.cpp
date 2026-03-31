class Twitter {
public:
    int count = 0;
    unordered_map<int, unordered_set<int>> following;  //key -> userId     value -> followeeId
    unordered_map<int, vector<pair<int, int>>> tweets;     //key -> userId     value -> count, userTweets
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++, tweetId});
        if (tweets[userId].size() > 10)    tweets[userId].erase(tweets[userId].begin());
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        priority_queue<pair<int, int>> q;
        for (int i = 0 ; i < tweets[userId].size() ; i++)   q.push(tweets[userId][i]);
        for (auto& others : following[userId]){
            for (auto& tweet : tweets[others]){
                q.push(tweet);
            }
        }
        while (ret.size() < 10 && !q.empty())   { 
            ret.push_back(q.top().second); 
            q.pop();
        }return ret;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].erase(followeeId);
    }
};
