/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:18:54 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int max_profit = 0, cur_job = 0, cur_worker = 0, res = 0;
		vector<pair<int, int>> jobs;

		for(int i = 0; i < difficulty.size(); ++i)
			jobs.push_back(make_pair(difficulty[i], profit[i]));

		sort(jobs.begin(), jobs.end(), [](pair<int, int>& a, pair<int, int>& b){return a.first < b.first;});

		sort(worker.begin(), worker.end());

		while(cur_worker < worker.size()){

			while(cur_job < difficulty.size() && jobs[cur_job].first <= worker[cur_worker]){
				max_profit = max(max_profit, jobs[cur_job].second);
				cur_job++;
			}

			res += max_profit;
			cur_worker++;
		}

		return res;
    }
};

int main(){
    Solution s;
    vector<int> difficulty{2,4,6,8,10}, profit{10,20,30,40,50}, worker{4,5,6,7};
    cout << s. maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}
