/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  1 18:37:54 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
		vector<int> dp(nums.size(), 1);

		int res = 1;

		for(int i = 1; i < nums.size(); ++i){

				if(nums[i-1] < nums[i])
					dp[i] = max(dp[i], dp[i-1] + 1);

			res = max(res, dp[i]);
		}
		return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,3,4,6,2};
    cout << s.findLengthOfLCIS(nums) << endl;
    return 0;
}
