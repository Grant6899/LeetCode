/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:34:47 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;

        vector<vector<int>> left(grid.size(), vector<int>(grid[0].size(), 0));
		vector<vector<int>> right(grid.size(), vector<int>(grid[0].size(), 0));
		vector<vector<int>> up(grid.size(), vector<int>(grid[0].size(), 0));
		vector<vector<int>> down(grid.size(), vector<int>(grid[0].size(), 0));

		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[0].size(); ++j)
				if(grid[i][j] == 'E')
					left[i][j] = (j - 1 >= 0 ? left[i][j-1] : 0) + 1;
				else if(grid[i][j] == 'W')
					left[i][j] = 0;
				else
					left[i][j] = (j - 1 >= 0 ? left[i][j-1] : 0);




		for(int i = 0; i < grid.size(); ++i)
			for(int j = grid[0].size() - 1; j >= 0; --j)
				if(grid[i][j] == 'E')
					right[i][j] = (j + 1 <= grid[0].size() - 1 ? right[i][j+1] : 0) + 1;
				else if(grid[i][j] == 'W')
					right[i][j] = 0;
				else
					right[i][j] = (j + 1 <= grid[0].size() - 1 ? right[i][j+1] : 0);



		for(int j = 0; j < grid[0].size(); ++j)
			for(int i = 0; i < grid.size(); ++i)
				if(grid[i][j] == 'E')
					up[i][j] = (i - 1 >= 0 ? up[i-1][j] : 0) + 1;
				else if(grid[i][j] == 'W')
					up[i][j] = 0;
				else
					up[i][j] = (i - 1 >= 0 ? up[i-1][j] : 0);



		for(int j = 0; j < grid[0].size(); ++j)
			for(int i = grid.size() - 1; i >= 0; --i)
				if(grid[i][j] == 'E')
					down[i][j] = (i + 1 <= grid.size() - 1 ? down[i+1][j] : 0) + 1;
				else if(grid[i][j] == 'W')
					down[i][j] = 0;
				else
					down[i][j] = (i + 1 <= grid.size() - 1 ? down[i+1][j] : 0);
		/*
        for(int i = 0; i < grid.size(); ++i){
			for(int j = 0; j < grid[0].size(); ++j)
                cout << down[i][j] << ' ';
            cout << endl;
        } */

		int res = 0;
		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[0].size(); ++j)
				if(grid[i][j] == '0')
					res = max(res, left[i][j] + right[i][j] + up[i][j] + down[i][j]);

		return res;
    }
};

int main(){
    vector<vector<char>> grid{{'0','E','0','0'},{'E','0','W','E'},{'0','E','0','0'}};
    Solution s;
    cout << s. maxKilledEnemies(grid) << endl;
    return 0;
}
