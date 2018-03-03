/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Mar  2 19:43:40 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);
        
        dp[0] = 0;
        
        for(int i = 0; i < coins.size(); ++i)
            for(int j = 0; j <= amount; ++j){
                if(j-coins[i] >= 0) 
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        
        return dp[amount] == amount + 1? -1 : dp[amount];
        
    }
};

int main(){
    vector<int> coins{186,419,83,408};
    Solution s;

    cout << s.coinChange(coins, 6249) << endl;
    
    return 0;
}
