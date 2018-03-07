/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 19:06:45 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
		dp[0] = 1;
		for(int i = 0; i <= target; ++i){
			for(int n : nums)
				if(i - n >= 0) dp[i] += dp[i-n];
		}

		return dp[target];
    }
};

int main(){
    Solution s;
    vector<int> nums{1, 2, 3};
    cout << s.combinationSum4(nums, 4) << endl;
    return 0;
}
