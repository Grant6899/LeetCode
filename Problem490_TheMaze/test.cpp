/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 13 20:54:17 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));

		return dfs(maze, destination, start[0], start[1], -1, visited);
    }


	bool dfs(vector<vector<int>>& maze, vector<int>& destination, int i, int j, int last_dir, vector<vector<bool>>& visited){
		//cout<< "head:" << i << ", " << j << "last_dir: " << last_dir << endl;
		while(last_dir != -1 && i + delta[last_dir][0] >= 0 && maze.size() > i + delta[last_dir][0] && j + delta[last_dir][1] >= 0 && maze[0].size() > j + delta[last_dir][1]
		&& maze[i + delta[last_dir][0]][ j + delta[last_dir][1]] == 0){
			i += delta[last_dir][0];
			j += delta[last_dir][1];
            //cout << "moving: " << i << "," << j << endl;
		}


		if(visited[i][j]) return false;

		if(i == destination[0] && j == destination[1]) return true;

		visited[i][j] = true;

		//cout<< i << ", " << j << "last_dir: " << last_dir << endl;
		for(int k = 0; k < 4; ++k){
			if( k != last_dir && dfs(maze, destination, i, j, k, visited) )
				return true;
		}

		return false;
	}

private:
	vector<vector<int>> delta{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main(){
    Solution s;
    vector<vector<int>> maze{{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> st{0, 4}, ed{4, 4};
    cout << s.hasPath(maze, st, ed) << endl;
    return 0;

}
