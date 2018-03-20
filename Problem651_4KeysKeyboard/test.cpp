/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 19 22:28:50 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxA(int N) {
		vector<long> dp(51, 0);

		for(int i = 1; i <= 50; ++i)
			dp[i] = i;

		for(int i = 4; i <= N; ++i){
			for(int j = 3; j < i; ++j){
				if(i - j >= 0 && dp[i - j] + (j - 2) * dp[i - j] > dp[i])
					dp[i] = dp[i - j] + (j - 2) * dp[i - j];
			}
		}
		return dp[N];
    }
};

int main(){
    Solution s;
    cout << s.maxA(30) << endl;
    return 0;
}
