/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 17:47:55 2018
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {

        if(data.empty() || data.back().first < timestamp)
            data.push(make_pair(timestamp, 1));
        else
            data.back().second++;

        cnt++;
        while(!data.empty() && data.front().first <= timestamp - 300){
            cnt -= data.front().second;
            data.pop();
        }
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!data.empty() && data.front().first <= timestamp - 300){
            cnt -= data.front().second;
            data.pop();
        }
        return cnt;
    }

    queue<pair<int, int>> data;
    int cnt = 0;
};

int main(){
    HitCounter hc;
    hc.hit(1);
    hc.hit(2);
    hc.hit(3);
    cout << hc.getHits(10) << endl;
    return 0;
}
