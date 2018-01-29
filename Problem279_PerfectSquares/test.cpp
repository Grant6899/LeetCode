/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 28 16:38:27 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i){
            if((int)sqrt(i) * (int)sqrt(i) == i){
                dp[i] = 1;
                continue;
            }
            else{
                for(int j = 1; j * j <= i; ++j){
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }

        for(int i = 0; i <= n; ++i)
            cout << i << " : " << dp[i] << endl;
        return dp[n];
    }
};

int main(){
    
    Solution s;

    cout << s.numSquares(7168) << endl;

    return 0;
}
