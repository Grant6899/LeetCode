/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Feb  3 12:41:16 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		int res = 0;


        for(int i = 0; i < matrix.size(); ++i){
			for(int j = 0; j < matrix[0].size(); ++j)
                dp[i][j] = matrix[i][j] - '0';
        }


		for(int i = 0; i < matrix.size(); ++i)
			for(int j = 0; j < matrix[0].size(); ++j){
				if(i - 1 >= 0 && j - 1 >= 0  && matrix[i][j] == '1' )
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
				res = max(res, dp[i][j]);
			}

   /*     for(int i = 0; i < matrix.size(); ++i){
			for(int j = 0; j < matrix[0].size(); ++j)
                cout << dp[i][j] << ' ';
            cout << endl;
        }*/

		return res * res;
    }
};

int main(){
    Solution s;
    vector<vector<char>> mat {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

    cout << s.maximalSquare(mat) << endl;

    return 0;
}
