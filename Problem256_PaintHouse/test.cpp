/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Mar 17 20:40:00 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		int n = costs.size();
		for (int i = 1; i < n; i++) {
			costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
			costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
			costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
		}
		return (n == 0) ? 0 : (min(costs[n - 1][0], min(costs[n - 1][1], costs[n - 1][2])));
	}
};

int main(){
    Solution s;
    vector<vector<int>> costs;
    cout << s.minCost(costs) << endl;
    return 0;
}


