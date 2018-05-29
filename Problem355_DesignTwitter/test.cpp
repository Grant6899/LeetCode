/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:48:11 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Twitter {
public:

	struct Tweet{
		int time, tweetId, userId;
		Tweet(int time_, int tweetId_, int userId_) : time(time_), tweetId(tweetId_), userId(userId_) {}
	};

    /** Initialize your data structure here. */
    Twitter() {
		tweet_cnt = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		posted[userId].push_back(Tweet(tweet_cnt, tweetId, userId));
		tweet_cnt++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
		vector<int> res;
		following[userId].insert(userId);
		auto com = [](Tweet& t1, Tweet& t2){ return t1.time < t2.time; };

		priority_queue<Tweet, vector<Tweet>, decltype(com)> pq(com);

		unordered_map<int, int> idx;

		for(int followee : following[userId]){
			if(!posted[followee].empty()){
				idx[followee] = posted[followee].size() - 1;
				pq.push(posted[followee][idx[followee]]);
			}
		}

		int feed_cnt = 10, i = 0;
		while(i < feed_cnt && !pq.empty()){

			auto latest = pq.top();
			res.push_back(latest.tweetId);
            i++;
			pq.pop();

			if(idx[latest.userId] > 0){
				idx[latest.userId]--;
				pq.push(posted[latest.userId][idx[latest.userId]]);
			}
		}
		return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

private:
	int tweet_cnt;
	unordered_map<int, unordered_set<int>> following;
	unordered_map<int, vector<Tweet>> posted;

};

int main(){
    Twitter tw;
    tw.postTweet(1, 5);
    tw.getNewsFeed(1);
    return 0;
}

