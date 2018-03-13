/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 12 23:45:37 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
		set<vector<vector<int>>> islands;

		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[0].size(); ++j){
				vector<vector<int>> island;
				dfs(i, j, 0, 0, island, grid);
				if(!island.empty())
                    islands.insert(island);

			}
		return islands.size();
    }

	bool dfs(int i, int j, int m, int n, vector<vector<int>>& island, vector<vector<int>>& grid){
		if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
			return false;

		grid[i][j] = 0;
		island.push_back({m, n});

		for(int k = 0; k < 4; k++){
			dfs(i + delta[k][0], j + delta[k][1], m + delta[k][0], n + delta[k][1], island, grid);
		}

		return true;
	}

private:
	vector<vector<int>> delta{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

};

int main(){
    Solution s;
    vector<vector<int>> grid{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};

    cout << s.numDistinctIslands(grid) << endl;
    return 0;
}
