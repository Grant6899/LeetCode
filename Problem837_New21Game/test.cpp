/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 18:17:18 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        // dp[i] = 1/W * { dp[i-W] + ... + dp[i-1] }

        if (K == 0 || N >= K + W) return 1.0;

        vector<double> dp(N + 1);
        dp[0] = 1.0;

        double Wsum = 1.0, res = 0.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = Wsum / W;
            if (i < K) Wsum += dp[i];
            else res += dp[i];

            if (i - W >= 0) Wsum -= dp[i - W];
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.new21Game(21, 17, 10) << endl;
    return 0;
}
