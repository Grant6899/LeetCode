/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  2 22:57:40 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;

		vector<vector<int>> max_len(matrix.size(), vector<int>(matrix[0].size(), 0));

		int res = 0;

		for(int i = 0; i < matrix.size(); ++i)
			for(int j = 0; j < matrix[0].size(); ++j){
				res = max(res, dfs(matrix, max_len, i, j) - 1);
			}
        /*for(int i = 0; i < matrix.size(); ++i){
			for(int j = 0; j < matrix[0].size(); ++j)
                cout << max_len[i][j] << " ";
            cout << endl;
        }*/


		return res;
    }

	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& max_len, int i, int j){
		if(max_len[i][j] > 0)
			return max_len[i][j] + 1;

        int longest = 1;
		for(int k = 0; k < 4; ++k)
			if( checkRange(i + delta[k][0], j + delta[k][1], matrix) && matrix[i + delta[k][0]][j + delta[k][1]] > matrix[i][j]){
                    longest = max(longest, dfs(matrix, max_len, i + delta[k][0], j + delta[k][1]));
			}

        max_len[i][j] = max(max_len[i][j], longest);
		return max_len[i][j] + 1;
	}

	bool checkRange(int x, int y, vector<vector<int>>& matrix){
		return (0 <= x && x < matrix.size() && 0 <= y && y < matrix[0].size());
	}

	const vector<vector<int>> delta{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main(){
    vector<vector<int>> mat{{1, 2}, {2, 3}};
    Solution s;
    cout << s. longestIncreasingPath(mat) << endl;
    return 0;
}
