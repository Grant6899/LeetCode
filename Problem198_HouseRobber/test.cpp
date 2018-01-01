/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 31 15:03:30 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        const int len = nums.size();
        if(len == 0)
            return 0;

        vector<int> dp(len, 0);
        
        dp[0] = nums[0];
        if(len == 1)
            return dp[0];

        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; ++i)
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        return dp[len-1];
    }
};

int main(){
    Solution s;
    vector<int> vec { 4, 3 ,1 ,2 ,5,6 };
    cout << s.rob(vec) << endl;
    return 0;
}
