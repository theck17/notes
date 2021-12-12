/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-12 11:16:38
 *   Description   ：
 */
using namespace std;
class Twitter {
private:
    vector<pair<int,int>>posts;
    unordered_map<int, unordered_map<int, int>>follows;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        posts.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        int count = 0;
        for(int i = posts.size() - 1; i >= 0 && count < 10; i--)
            if(posts[i].first == userId || follows[userId][posts[i].first])
                feed.push_back(posts[i].second), count++;
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 *obj->unfollow(followerId,followeeId);
 */ 

int main(){
    return 0;
}
