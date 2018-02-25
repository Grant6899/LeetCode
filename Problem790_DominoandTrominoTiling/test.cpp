/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Feb 25 08:35:40 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        vector<uint64_t> dp(1001, 0);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

       for(int i = 4; i <= N; ++i){
            uint64_t temp = 0;

            for(int j = 0; j <= i - 3; ++j){
                    temp += dp[j] * 2;
            }

            temp += dp[i-1] + dp[i-2];
            dp[i] = temp % (1000000000+7);
        }

        return dp[N];
    }
};

int main(){
    Solution s;
    cout << s.numTilings(10) << endl;
    return 0;
}
