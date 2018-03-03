/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Mar  2 20:46:06 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;

        if(coins.empty())
            return 0;

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); ++i){
            for(int j = 0; j <= amount; ++j){
                if(j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
                //cout << dp[j] << " ";
            }
            //cout << endl;
        }
        return dp[amount];
    }
};

int main(){
    vector<int> coins{1, 2, 5};
    Solution s;
    cout << s.change(11, coins) << endl;
    return 0;
}
