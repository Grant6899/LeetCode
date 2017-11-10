#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<cmath>

using namespace std;
//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {

		if (intervals.size() == 0)
			return{};
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
		result.push_back(intervals[0]);

		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].end <= result.back().end)
				continue;
			else if (intervals[i].start <= result.back().end) {
				result.back().end = intervals[i].end;
			}
			else
				result.push_back(intervals[i]);
		}
		return result;
	}
};


int main() {
	Solution s;

	std::vector<Interval> vec{};
	auto ans = s.merge(vec);

	return 0;
}