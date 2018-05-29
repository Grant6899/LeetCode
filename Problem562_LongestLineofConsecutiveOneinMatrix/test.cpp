/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr 16 22:59:18 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        vector<vector<vector<int>>> dp(M.size(), vector<vector<int>>(M[0].size(), vector<int>(4, 0)));

        int res = 0;
        for(int i = 0; i < M.size(); ++i)
            for(int j = 0; j < M[0].size(); ++j){
                for(int k = 0; k < 4; ++k)
                    dp[i][j][k] = M[i][j];

                if(M[i][j]){
                    if(inMatrix(i - 1, j, M) && dp[i-1][j][0])
                        dp[i][j][0] = dp[i-1][j][0] + 1;

                    res = max(res, dp[i][j][0]);

                    if(inMatrix(i, j - 1, M) && dp[i][j-1][1])
                        dp[i][j][1] = dp[i][j-1][1] + 1;

                    res = max(res, dp[i][j][1]);
                    if(inMatrix(i - 1, j - 1, M) && dp[i-1][j-1][2])
                        dp[i][j][2] = dp[i-1][j-1][2] + 1;
                    res = max(res, dp[i][j][2]);
                }
            }

        for(int i = M.size() - 1; i >= 0; ++i)
            for(int j = 0; j < M[0].size(); ++j){
                if(inMatrix(i + 1, j - 1, M) && dp[i+1][j-1][3])
                        dp[i][j][3] = dp[i+1][j-1][3] + 1;
                res = max(res, dp[i][j][2]);
            }

        return res;

    }

    bool inMatrix(int x, int y, vector<vector<int>>& M){
        return (0 <= x && x < M.size() && 0 <= y && y < M[0].size());
    }
};

int main(){
    vector<vector<int>> M{{0, 1, 1, 0}, {0, 1, 1, 0}, {0,0,0,1}};
    Solution s;
    cout << s. longestLine(M) << endl;
    return 0;
}
