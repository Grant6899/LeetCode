/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Mar 17 20:17:45 2018
 ************************************************************************/

#include<iostream>
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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
		if(intervals.empty())
			return 0;
		
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){return a.end < b.end;});
		int cur_end = intervals[0].end, cnt = 1;
		for(int i = 1; i < intervals.size(); ++i){
			if(intervals[i].start >= cur_end){
				cur_end = intervals[i].end;
				cnt++;
			}
		}
		return intervals.size() - cnt;
    }
};

int main() {
	Solution s;

	std::vector<Interval> vec{};
	auto ans = s. eraseOverlapIntervals(vec);

	return 0;
}

