/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:22:50 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int res = 0;
        for(int x1 = 0; x1 + 2 < grid.size(); ++x1)
            for(int y1 = 0; y1 + 2 < grid[0].size(); ++y1)
                if(isMagic(x1, y1, x1 + 2, y1 + 2, grid)){
                    res++;
                }

        return res;
    }

    bool isMagic(int x1, int y1, int x2, int y2, vector<vector<int>>& grid){
        //cout << "x1:" << x1 << " y1:" << y1 << endl;
        int size = x2 - x1 + 1;

        int diag1 = 0;
        for(int i = 0; i < size; ++i){
            diag1 += grid[x1 + i][y1 + i];
        }
        //cout << "diag1: " << diag1 << endl;
        int diag2 = 0;
        for(int i = 0; i < size; ++i){
            //cout << "adding " << x1 + i << " " << x1 + y1 + size - 1 - (x1 + i) << endl;
            diag2 += grid[x1 + i][x1 + y1 + size - 1 - (x1 + i)];
        }
        //cout << "diag2: " << diag2 << endl;


        if(diag1 != diag2) return false;
        vector<bool> visited(9, false);
        for(int i = 0; i < size; ++i){
            int row_sum = 0, col_sum = 0;
            for(int j = 0; j < size; ++j){
                if(grid[x1 + i][y1 + j] > 9 || grid[x1 + i][y1 + j] < 1 || visited[grid[x1 + i][y1 + j]]) return false;
                visited[grid[x1 + i][y1 + j]] = true;
                col_sum += grid[x1 + j][y1 + i];
                row_sum += grid[x1 + i][y1 + j];
            }
            //cout << "i: " << i << " col_sum: " << col_sum << " row_sum: " << row_sum << endl;
            if(row_sum != col_sum || diag1 != row_sum) return false;
        }

        return true;
    }
};

int main(){
    vector<vector<int>> grid{{4,3,8,4}, {9,5,1,9}, {2,7,6,2}};
    Solution s;
    cout << s. numMagicSquaresInside(grid) << endl;
    return 0;
}
