/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 25 17:53:06 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;

        vector<int> left(grid.size()), top(grid[0].size());

        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j){
                left[i] = max(left[i], grid[i][j]);
                top[j] = max(top[j], grid[i][j]);
            }

        int res = 0;
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                res += min(left[i], top[j]) - grid[i][j];

        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid{{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    cout << s. maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}
