/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  1 18:26:29 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
		vector<int> dp(n + 1, 0);

		for(int i = 2; i <= n; ++i){
			dp[i] = i;

			for(int j = i - 1; j >= 1; --j){
				if(i % j == 0){
					dp[i] = dp[j] + i / j;
					break;
				}
			}
		}

		return dp.back();
    }
};


int main(){
    Solution s;

    cout << s.minSteps(10) << endl;
    return 0;
}
