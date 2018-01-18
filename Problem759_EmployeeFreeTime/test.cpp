/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 17 19:32:42 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> working_time;

        for(int i = 0; i < schedule.size(); ++i)
        for(int j = 0; j < schedule[i].size(); ++j){
            working_time.push_back(schedule[i][j]);
        }

        working_time = merge(working_time);

        vector<Interval> res = getFreeTime(working_time);

        return res;
    }

private:
    vector<Interval> getFreeTime(const vector<Interval>& working_time){
        vector<Interval> res;

        if(working_time.size() < 2)
            return res;

        int left = 0;
        while(left < working_time.size() - 1){
            res.push_back(Interval(working_time[left].end, working_time[left+1].start));
            ++left;
        }
        return res;
    }

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


int main(){
    Solution s;
    vector<vector<Interval>> worker_schedule {{ Interval(1,2),Interval(5,6)},{Interval(1,3)},{Interval(4,10)}};
    
    auto ans = s.employeeFreeTime(worker_schedule);

    for(int i = 0; i < ans.size(); ++i)
        cout << "[" << ans[i].start << ", " << ans[i].end << "]\n";

    return 0;
}
