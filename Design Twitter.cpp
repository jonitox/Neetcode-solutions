#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:s
    int count = 0;  // counter to maintain the order of tweets
    unordered_map<int, unordered_set<int>> follows; // followerId -> set of followeeIds
    map<int, pair<int,int>, greater<int>> tweets; // count -> {userId, tweetId}
    
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[count++] = {userId, tweetId};
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        for(auto& t: tweets){ // from most recent to least
            int tweetUserId = t.second.first;
            if(tweetUserId != userId && 
            follows[userId].count(tweetUserId) ==0){
                continue;
            }
            ret.push_back(t.second.second);
            if(ret.size()==10)
                break;
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

int main() {
}