class Twitter {
public:
    unordered_map<int, unordered_set<int>> followings;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int ts;
    
    /** Initialize your data structure here. */
    Twitter() {
        ts = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ts++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feeds;
        priority_queue<tuple<int, int, int>> pq;
        followings[userId].insert(userId);
        for (int u: followings[userId]) {
            if (tweets[u].empty()) continue;
            int i = tweets[u].size()-1;
            pq.push({tweets[u][i].first, u, i});
        }
        while (!pq.empty() && feeds.size()<10) {
            auto [t, u, i] = pq.top();
            //cout << t << u << tweets[u][i].second;
            pq.pop();
            feeds.push_back(tweets[u][i].second);
            if (i-1>=0) {
                pq.push({tweets[u][i-1].first, u, i-1});
            }
        }
        return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
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
