/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:20:38 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
		vector<int> island_count(2501, 0);


		int color = 2, res = 0;

		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[0].size(); ++j){
				if(grid[i][j] == 1){
					int count = 0;
					colorIsland(i, j, color, grid, count);
					island_count[color] = count;
					color++;
				}
			}

		if(island_count[2] == grid.size() * grid[0].size())
			return grid.size() * grid[0].size();

		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[0].size(); ++j){
				if(grid[i][j] == 0){

					int cur_count = 0;
                    set<int> color_added;
					for(int k = 0; k < 4; ++k)
                        if(0 <= i + delta[k][0] && i + delta[k][0] < grid.size() && 0 <= j + delta[k][1] && j + delta[k][1] < grid[0].size() && color_added.count(grid[i + delta[k][0]][j + delta[k][1]]) == 0){
						    cur_count += island_count[grid[i + delta[k][0]][j + delta[k][1]]];
                            color_added.insert(grid[i + delta[k][0]][j + delta[k][1]]);
                        }
					res = max(cur_count + 1, res);

				}
			}
        return res;
    }

	void colorIsland(int i, int j, int new_color, vector<vector<int>>& grid, int& count){
		grid[i][j] = new_color;
		count++;

		for(int k = 0; k < 4; ++k){
			if(0 <= i + delta[k][0] && i + delta[k][0] < grid.size() && 0 <= j + delta[k][1] && j + delta[k][1] < grid[0].size() && grid[i + delta[k][0]][j + delta[k][1]] == 1)
				colorIsland(i + delta[k][0], j + delta[k][1], new_color, grid, count);
		}
	}

	const vector<vector<int>> delta{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main(){
    Solution s;
    vector<vector<int>> grid{{1,0},{0, 1}};
    cout << s. largestIsland(grid) << endl;
    return 0;
}
