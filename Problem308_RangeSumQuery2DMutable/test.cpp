/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu May  3 21:22:36 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> _bit, _mat;
    
    void add(int i, int j, int val){
        i++;
        j++;
        
        for(int ii = i;ii < _bit.size(); ii += lowbit(ii))
        for(int jj = j;jj < _bit[0].size(); jj += lowbit(jj))
            _bit[ii][jj] += val;
    }
    
    int lowbit(int i){
        return i & (-i);
    }
    
    int getSum(int i, int j){
        int res = 0;
        i++;
        j++;
        for(int ii = i;ii > 0; ii -= lowbit(ii))
        for(int jj = j;jj > 0; jj -= lowbit(jj))
            res += _bit[ii][jj];
        return res;
    }
public:
    NumMatrix(vector<vector<int>> mat) : _mat(mat){
        if(mat.empty() || mat[0].empty())
            return;
        
        _bit = vector<vector<int>>(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
        
        for(int i = 0; i < mat.size(); i++)
            for(int j = 0; j < mat[0].size(); j++)
                add(i, j, mat[i][j]);
    }
    
    void update(int i, int j, int new_val){
        add(i, j, new_val - _mat[i][j]);
        _mat[i][j] = new_val;
    }
    
 
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) + getSum(row1 - 1, col1 - 1) - getSum(row1 - 1, col2) - getSum(row2, col1 - 1);
    }
};

int main(){
    vector<vector<int>> mat{{3,0,1},{5,6,3},{1,2,0}};
    NumMatrix nummat(mat);
    return 0;
}

