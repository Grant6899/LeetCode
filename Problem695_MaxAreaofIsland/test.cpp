/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 14 11:07:57 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        for(int i = 0; i < grid.size(); ++i)
        for(int j = 0; j < grid[0].size();++j)
            if(grid[i][j] == 1){
                res = max(res, maxArea(grid, i, j));    
            }

        return res;
    }

    int maxArea(vector<vector<int>>& grid, int i, int j){
        if(i >= 0 & i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
            grid[i][j] = 0;
            return 1 + maxArea(grid, i-1, j) + maxArea(grid, i+1, j) + maxArea(grid, i, j-1) + maxArea(grid, i, j+1);
        }
        return 0;
    }
};


int main(){
    vector<vector<int>> map {{0,0,1,0,0,0,0,1,0,0,0,0,0},
 {0,0,0,0,0,0,0,1,1,1,0,0,0},
 {0,1,1,0,1,0,0,0,0,0,0,0,0},
 {0,1,0,0,1,1,0,0,1,0,1,0,0},
 {0,1,0,0,1,1,0,0,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    Solution s;

    cout << s.maxAreaOfIsland(map) << endl;

    return 0;
}
