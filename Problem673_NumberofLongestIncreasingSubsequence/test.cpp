/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  1 18:36:11 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
		vector<pair<int, int>> dp(nums.size(), make_pair(1, 1));

		dp[0] = make_pair(1,1);

		int res = 1, maxlen = 1;

		for(int i = 1;i < nums.size(); ++i){
			int last_added = 0;
			for(int j = 0; j < i; ++j){
				if(nums[j] < nums[i] && dp[i].first < dp[j].first + 1){
					dp[i].first = dp[j].first + 1;
					dp[i].second = dp[j].second;
				}
				else if(nums[j] < nums[i] && dp[i].first == dp[j].first + 1){
					dp[i].second += dp[j].second;
				}
			}

			//cout << i << ": " << dp[i].first << " , " << dp[i].second << endl;

			if(maxlen == dp[i].first)
				res += dp[i].second;

			if(dp[i].first > maxlen){
				maxlen = dp[i].first;
				res = dp[i].second;
			}

		}

		return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,3,5,4,7};
    cout << s.findNumberOfLIS(nums) << endl;
    return 0;
}
