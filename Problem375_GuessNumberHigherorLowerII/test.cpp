/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 25 17:30:42 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));

		for(int i = 1; i <= n; i++)
			dp[i][i] = 0;

		for(int k = 2; k <= n; ++k)
			for(int i = 1; i <= n - k + 1; ++i)
				for(int j = i; j <= i + k - 1; ++j){
                    int left = i > j - 1? 0 : dp[i][j-1];
                    int right = j + 1 > i+k-1? 0 : dp[j+1][i+k-1];
					dp[i][i+k-1] = min(dp[i][i+k-1], j + max(left, right));
                }

		return dp[1][n];
    }
};

int main(){
    Solution s;
    cout << s. getMoneyAmount(10) << endl;
    return 0;
}
