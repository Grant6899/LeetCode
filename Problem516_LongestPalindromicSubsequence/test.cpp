/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 16 12:42:43 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty())
            return 0;

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int len = s.size();

        for ( int i = 0; i < len; ++i ){
            dp[i][i] = 1;
            if ( i + 1 < len){
                if (s[i] == s[i+1])
                    dp[i][i+1] = 2;
                else
                    dp[i][i+1] = 1;
            }
        }

        for (int l = 2; l < s.size(); ++l){
            for ( int i = 0; i + l < s.size(); ++i ){
                int j = i + l;
                if (s[i] == s[j]){
                    int tmp = max(dp[i+1][j], dp[i][j-1]);
                    dp[i][j] = max(tmp, dp[i+1][j-1] + 2);    
                }
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[0][len-1];
    
    }
};

int main(){
    Solution s;

    cout << s.longestPalindromeSubseq("cbbd") << endl;

    return 0;
}
