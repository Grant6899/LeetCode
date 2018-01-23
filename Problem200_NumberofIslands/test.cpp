/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 22 20:51:32 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int res = 0;
        
        for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++)
            if(!visited[i][j] && grid[i][j] == '1'){
                find(i, j, visited, grid);
                res++;
            }
        return res;
    }

    void find(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && !visited[i][j] && grid[i][j] == '1'){
            visited[i][j] = true;
            find(i-1, j, visited, grid);
            find(i+1, j, visited, grid);
            find(i, j-1, visited, grid);
            find(i, j+1, visited, grid);
        }
    }

};

int main(){
    vector<vector<char>> grid {{'1','1','1'}, {'0','1','0'}, {'1','1','1'}}; //{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution s;

    cout << s.numIslands(grid) << endl;
    return 0;
}

