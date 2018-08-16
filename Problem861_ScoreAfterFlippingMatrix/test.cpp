/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jul  1 21:03:48 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        
        for(int i = 0; i < A.size(); i++)
            if(A[i][0] == 0){
                cout << "toggle row: " << i << endl;
                toggleRow(A, i);
            }
        
        for(int j = 1; j < A[0].size(); j++){
            
            int cnt_one = 0;
            for(int i = 0; i < A.size(); i++)
                cnt_one += A[i][j];
            
            if(cnt_one <= A.size() / 2)
                toggleCol(A, j);
            
            for(int ii = 0; ii < A.size(); ++ii){
                for(int jj = 0; jj < A[0].size(); ++jj)
                    cout << A[ii][jj] << ' ';
                cout << endl;
            }
            cout << endl;
        }
        
        int res = 0;
        for(int j = 0; j < A[0].size(); j++){
            res *= 2;
            for(int i = 0; i < A.size(); ++i)
                res += A[i][j];
        }
        
        return res;
    }
    
    void toggleRow(vector<vector<int>>& A, int i){
        for(int j = 0; j < A[i].size(); ++j)
            A[i][j] = 1 - A[i][j];
    }
    
    void toggleCol(vector<vector<int>>& A, int j){
        for(int i = 0; i < A.size(); ++i)
            A[i][j] = 1 - A[i][j];
    }
};

int main(){
    Solution s;
    vector<vector<int>> A{{0,0,1,1},{1,0,1,0},{1,1,0,0}};

    cout << s.matrixScore(A) << endl;

    return 0;
}
