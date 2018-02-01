/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  1 18:39:25 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));


		for(int i = 0; i < nums.size(); ++i){
			dp[i][i] = nums[i];
			if(i+1 < nums.size())
				dp[i][i+1] = abs(nums[i] - nums[i+1]);
		}

		for(int i = 2; i < nums.size(); ++i)
			for(int j = 0; i + j < nums.size(); ++j)
				dp[j][j+i] = max(nums[j] - dp[j+1][j+i], nums[j+i] - dp[j][j+i-1]);

		return dp[0][nums.size()-1] >= 0;
    }
};

int main(){
    vector<int> nums{1,5,2};
    Solution s;

    cout << s.PredictTheWinner(nums) << endl;
    return 0;
}
