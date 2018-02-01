/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  1 18:32:20 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
		
		for(int num : nums)
			count[num]++;
		
		vector<int> dp(10001, 0);
		
		dp[1] = count[1] * 1;
		
		for(int i = 2; i <= 10000; ++i)
			dp[i] = max(dp[i-1], dp[i-2] + count[i] * i);
		
		return dp[10000];
    }
};

int main(){
    Solution s;
    vector<int> nums{1,2,5,4,2,5};
    cout << s.deleteAndEarn(nums) << endl;
    return 0;
}
