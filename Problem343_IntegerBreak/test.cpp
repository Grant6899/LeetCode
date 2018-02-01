/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  1 18:31:07 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
		vector<int> dp(n+1, 0);

		for(int i = 2; i <= n; ++i){
			dp[i] = i - 1;

			for( int j = 2; j <= i / 2; ++j){
				dp[i] = max(dp[i], max(j, dp[j]) * max(i-j, dp[i-j]));
                //if(i == 6)
                    //cout << "i: " << i << " j: " << j << " dp[j]: " << dp[j] << " i-j: " << i - j << " dp[i-j]: " << dp[i-j] << endl;
            }
		}
		return dp[n];
    }
};

int main(){
    Solution s;
    
    cout << s.integerBreak(10) << endl;

    return 0;
}
