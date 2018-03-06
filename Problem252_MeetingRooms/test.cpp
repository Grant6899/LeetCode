/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:45:28 2018
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
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto com = [](Interval& a, Interval& b){ return a.start < b.start;};
		sort(intervals.begin(), intervals.end(), com);
		
		for(int i = 1; i < intervals.size(); ++i)
			if(intervals[i].start < intervals[i-1].end)
				return false;
			
		return true;
    }
};

int main(){
	Solution s;
	vector<Interval> intervals{Interval(0, 30), Interval(5, 10), Interval(15, 20)};
	cout << s.canAttendMeetings(intervals) << endl;
	return 0;
}