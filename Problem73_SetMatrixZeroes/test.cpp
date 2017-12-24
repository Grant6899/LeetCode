/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 23 13:15:44 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int last = -1;
        for(int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j)
            if(matrix[i][j] == 0){
                last = i;
                break;
            }
        }

        if(last == -1)
            return;

        for(int i = 0; i < last; ++i){
            bool row_zero = false;
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 0){
                    matrix[last][j] = 0;
                    row_zero = true;
                }
            }

            if(row_zero)
                for(int j = 0; j < matrix[0].size();++j)
                    matrix[i][j] = 0;   
        }

        for(int j = 0; j < matrix[0].size();++j){
            if(matrix[last][j] == 0){
                for (int i = 0; i < matrix.size(); ++i)
                    matrix[i][j] = 0;
            }

            matrix[last][j] = 0;
        }

    

    return;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat { {1,1,1,1},
                              {1,1,0,1},
                              {1,0,1,0},
                              {1,1,1,0} };
    s.setZeroes(mat);

    for(int i = 0; i < mat.size();++i){
        for (int j = 0; j < mat[0].size();++j)
            cout << mat[i][j] << "|";
        cout << endl;
    }

    return 0;
}

