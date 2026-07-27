class Twitter {
private:
    int timeStamp;
    // Map: userId -> vector of pair<timestamp, tweetId>
    unordered_map<int, vector<pair<int, int>>> tweets;
    // Map: userId -> set of followeeIds
    unordered_map<int, unordered_set<int>> follows;

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // Increment global clock so we know the absolute order of tweets
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Priority queue (max-heap) storing pair<timestamp, tweetId>
        priority_queue<pair<int, int>> maxHeap;
        
        // Ensure user follows themselves so their own tweets show in their feed
        follows[userId].insert(userId);
        
        // Push recent tweets from every person the user follows
        for (int followeeId : follows[userId]) {
            const auto& userTweets = tweets[followeeId];
            
            // Only examine up to the 10 most recent tweets per user
            int count = 0;
            for (int i = userTweets.size() - 1; i >= 0 && count < 10; --i, ++count) {
                maxHeap.push(userTweets[i]);
            }
        }
        
        // Pop the 10 most recent tweets across all followed users
        vector<int> res;
        while (!maxHeap.empty() && res.size() < 10) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // Users cannot unfollow themselves
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};