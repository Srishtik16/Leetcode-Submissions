class Twitter {
public:
    map<int, set<pair<int, int>>> tweets;
    map<int, set<int>> followers;
    int timeNow;
    Twitter() {
        timeNow = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(tweets[userId].size() >= 10) {
            tweets[userId].erase(tweets[userId].begin());
        }
        tweets[userId].insert({timeNow++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        set<pair<int, int>> newsFeed;
        for(auto x: tweets[userId]) {
            if(newsFeed.size() < 10) {
                newsFeed.insert(x);
            }
            else {
                if((*newsFeed.begin()).first < x.first) {
                    newsFeed.erase(newsFeed.begin());
                    newsFeed.insert(x);
                }
            }
        }
        for(auto followee: followers[userId]) {
            for(auto x: tweets[followee]) {
                if(newsFeed.size() < 10) {
                    newsFeed.insert(x);
                }
                else {
                    if((*newsFeed.begin()).first < x.first) {
                        newsFeed.erase(newsFeed.begin());
                        newsFeed.insert(x);
                    }
                }
            }
        }
        vector<int> orderedFeed;
        for(auto x: newsFeed) {
            orderedFeed.push_back(x.second);
            if(orderedFeed.size() == 10) {
                break;
            }
        }
        reverse(orderedFeed.begin(), orderedFeed.end());
        return orderedFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers[followerId].find(followeeId) != followers[followerId].end()) {
            followers[followerId].erase(followers[followerId].find(followeeId));
        }
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