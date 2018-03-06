/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:37:30 2018
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        auto com = [](Interval& a, Interval& b){return a.start < b.start;};
		sort(intervals.begin(), intervals.end(), com);
		priority_queue<int, vector<int>, greater<int>> endpoints;
		
		for(Interval interval : intervals){
			if(!endpoints.empty() && interval.start >= endpoints.top()) 
				endpoints.pop();
			endpoints.push(interval.end);
		}
		
		return endpoints.size();
    }
};

int main(){
    Solution s;
    vector<Interval> intervals{Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    cout << s.minMeetingRooms(intervals) << endl;

    return 0;
}
