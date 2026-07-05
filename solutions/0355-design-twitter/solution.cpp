class Twitter {
private:
    int timestamp;
    unordered_map<int,unordered_set<int>>following;
    unordered_map<int,vector<pair<int,int>>>tweets;//userid->vevctor of tweets by that user in <timestamp,tweetid> format 
public:
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp,tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        unordered_set<int> seen_tweets; 
        
        for (int i = 0; i < 10; i++) {
            int max_timestamp = -1;
            int best_tweet_id = -1;
            
            // 1. Check the user's own tweets (loop backward to find the latest unseen tweet)
            for (int j = tweets[userId].size() - 1; j >= 0; j--) {
                auto current = tweets[userId][j];
                if (!seen_tweets.count(current.second)) {
                    if (current.first > max_timestamp) {
                        max_timestamp = current.first;
                        best_tweet_id = current.second;
                    }
                    break; // Found the newest unseen tweet for this user, move to next person
                }
            }
            
            // 2. Loop over followed users
            for (auto u : following[userId]) {
                // Loop backward to find the latest unseen tweet for this followee
                for (int j = tweets[u].size() - 1; j >= 0; j--) {
                    auto current = tweets[u][j];
                    if (!seen_tweets.count(current.second)) {
                        if (current.first > max_timestamp) {
                            max_timestamp = current.first;
                            best_tweet_id = current.second;
                        }
                        break; // Found the newest unseen tweet for this user, move to next person
                    }
                }
            }
            
            // If we found a valid most-recent tweet, add its ID to the feed
            if (best_tweet_id != -1) {
                feed.push_back(best_tweet_id);
                seen_tweets.insert(best_tweet_id);
            } else {
                break; // No more tweets left to process
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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
