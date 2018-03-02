/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:24:34 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size() + 2, 0));

		nums.insert(nums.begin(), 1);
		nums.push_back(1);

		for(int len = 0; len <= n; ++len){

			for(int i = 0; i <= n + 1 - len; ++i){
				int j = i + len - 1;

				for(int k = i; k <= j; ++k)
					dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j]);
			}
		}
		return dp[1][n];
    }
};

int main(){
    vector<int> nums{3, 1, 5, 8};
    Solution s;
    cout << s.maxCoins(nums) << endl;
    return 0;
}
