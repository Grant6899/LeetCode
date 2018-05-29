/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:45:47 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));

		dp[0][0] = 1;

		int res = 0;
		for(int i = 1; i <= t.size(); ++i)
			for(int j = 1; j <= s.size(); ++j){
				if(t[i - 1] == s[j - 1]){
					for(int k = 0; k < j; ++k)
						dp[i][j] += dp[i-1][k];
				}
			}

        for(int i = 0; i <= s.size(); ++i)
			res += dp[t.size()][i];

       /*
		for(int i = 0; i < t.size() + 1; ++i){
			for(int j = 0; j < s.size() + 1; ++j)
				cout << dp[i][j] << " ";
			cout << endl;
		}*/

		return res;
    }
};

int main(){
    Solution s;
    cout << s.numDistinct("babgbag", "bag") << endl;
    return 0;
}
