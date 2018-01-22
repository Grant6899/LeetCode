/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 21 19:28:45 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> res;

        if(matrix.empty())
            return res;
        
        vector<vector<bool>> pacific(matrix.size(), vector<bool>(matrix[0].size(), false));
        auto atlantic = pacific;
        
        for(int i = 0; i < matrix.size(); ++i)
        for(int j = 0; j < matrix[0].size(); ++j){
            if(i == 0 || j == 0) scanPacific(i, j, matrix, pacific);
            if(i == matrix.size() - 1 || j == matrix[0].size() - 1) scanAtlantic(i, j, matrix, atlantic); 
        }

        for(int i = 0; i < matrix.size(); ++i)
        for(int j = 0; j < matrix[0].size(); ++j){
            if(atlantic[i][j] && pacific[i][j])
                res.push_back(make_pair(i, j));
        }
  /*
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j)
                cout << atlantic[i][j] << " ";
            cout << endl;
        }
  

*/

        return res;
    }

    void scanAtlantic(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& atlantic){
        
        atlantic[i][j] = true;
        
        if(i - 1>= 0 && i - 1< matrix.size() && j >= 0 && j < matrix[0].size() && atlantic[i-1][j] == false && matrix[i][j] <= matrix[i-1][j])
            scanAtlantic(i-1, j, matrix, atlantic);
        if(i + 1>= 0 && i + 1< matrix.size() && j >= 0 && j < matrix[0].size() && atlantic[i+1][j] == false && matrix[i][j] <= matrix[i+1][j])
            scanAtlantic(i+1, j, matrix, atlantic);
        if(i >= 0 && i < matrix.size() && j - 1 >= 0 && j - 1 < matrix[0].size() && atlantic[i][j-1] == false && matrix[i][j] <= matrix[i][j-1])
            scanAtlantic(i, j-1, matrix, atlantic);
        if(i >= 0 && i < matrix.size() && j + 1 >= 0 && j + 1 < matrix[0].size() && atlantic[i][j+1] == false && matrix[i][j] <= matrix[i][j+1])
            scanAtlantic(i, j+1, matrix, atlantic);
 
    }

    void scanPacific(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& pacific){
        
        pacific[i][j] = true;
        
        if(i - 1>= 0 && i - 1< matrix.size() && j >= 0 && j < matrix[0].size() && pacific[i-1][j] == false && matrix[i][j] <= matrix[i-1][j])
            scanPacific(i-1, j, matrix, pacific);
        if(i + 1>= 0 && i + 1< matrix.size() && j >= 0 && j < matrix[0].size() && pacific[i+1][j] == false && matrix[i][j] <= matrix[i+1][j])
            scanPacific(i+1, j, matrix, pacific);
        if(i >= 0 && i < matrix.size() && j - 1 >= 0 && j - 1 < matrix[0].size() && pacific[i][j-1] == false && matrix[i][j] <= matrix[i][j-1])
            scanPacific(i, j-1, matrix, pacific);
        if(i >= 0 && i < matrix.size() && j + 1 >= 0 && j + 1 < matrix[0].size() && pacific[i][j+1] == false && matrix[i][j] <= matrix[i][j+1])
            scanPacific(i, j+1, matrix, pacific);
 
    }


};

int main(){
    Solution s;

    vector<vector<int>> mat {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    
    auto ans = s.pacificAtlantic(mat);

    for(auto ele : ans)
        cout << ele.first << ", " << ele.second << endl;

    return 0;
}
