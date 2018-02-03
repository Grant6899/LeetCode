/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 26 22:38:17 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<pair<int, int>>> dp(matrix.size(), vector<pair<int,int>>(matrix[0].size(),{0, 0} ));
        int res = 0;  
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == '1'){
                    dp[i][j] = make_pair(1, 1);
                
                    if(i - 1 >= 0 && j - 1 >= 0){
                        dp[i][j].first = min(dp[i-1][j-1].first, dp[i-1][j].first) + 1;
                        dp[i][j].second = min(dp[i-1][j-1].second, dp[i][j-1].second) + 1;
                    }
                    else if(i - 1 >= 0)
                        dp[i][j].first = dp[i-1][j].first + 1;
                    else if(j - 1 >= 0)
                        dp[i][j].second = dp[i][j-1].second + 1;
                }
                else
                    dp[i][j] = make_pair(0, 0);

                res = max(res, dp[i][j].first * dp[i][j].second);
            }

        return res;
    }

};

int main(){

    Solution s;

    vector<vector<char>> mat{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    
    cout << s.maximalRectangle(mat) << endl;

    return 0;
}
