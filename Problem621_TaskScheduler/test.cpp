/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:26:12 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> counts;

		for(char t : tasks)
			counts[t]++;

		auto com = [](pair<char, int>& a, pair<char, int>& b){return a.second < b.second;};

		priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(com)> pq(com);

		for(auto c : counts)
			pq.push(make_pair(c.first, c.second));


		int cycle_len = n + 1, res = 0, taskdid = 0;

		while(!pq.empty()){
			vector<pair<char, int>> tobeaddback;
			taskdid = 0;
			for(int i = 0; i < cycle_len; ++i){
				if(!pq.empty()){
					tobeaddback.push_back(pq.top());
					pq.pop();
					taskdid++;
				}
				res++;
			}

			for(auto t : tobeaddback){
				if(--t.second > 0)
					pq.push(t);
			}
		}

		res -= cycle_len - taskdid;

		return res;
    }
};

int main(){
    Solution s;
    vector<char> tasks{'A', 'A', 'B', 'B'};
    cout << s.leastInterval(tasks, 3) << endl;
    return 0;
}
