/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 18:52:41 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
		if(costs.empty())
			return 0;

        vector<vector<int>> dp(costs.size() + 1, vector<int>(costs[0].size(), INT_MAX));

		for(int i = 0; i < costs[0].size(); ++i)
			dp[0][i] = 0;

		for(int i = 1; i <= costs.size(); ++i){

			for(int j = 0; j < costs[0].size(); ++j)
				for(int k = 0; k < costs[0].size(); ++k){

					if(i == 1 || k != j){

                                            //cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << " dp[" << i-1 << "][" << k << "]: " << dp[i-1][k] << " costs[" << i << "][" << j << "]: " << costs[i][j] << endl;
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i-1][j]);
                    }
				}
		}

        int res = INT_MAX;
        for(int i = 0; i < costs[0].size(); ++i)
            res = min(res, dp[costs.size()][i]);
		return res;
    }
};

int main(){
    vector<vector<int>> costs{{1,5,7}, {3,1,4}};
    Solution s;
    cout << s.minCostII(costs) << endl;
    
    return 0;
}
