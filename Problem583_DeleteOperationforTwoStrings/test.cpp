/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Dec 12 20:13:33 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        for (int i = 1; i <= len1; ++i)
        for (int j = 1; j <= len2; ++j){
            if (word1[i] == word2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

        return len1 + len2 - 2 * dp[len1][len2];
    }
};

int main(){
    string s1 = "a", s2 = "b";
    Solution s;
    cout << s.minDistance(s1, s2) << endl;

    return 0;
}


