/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:02:07 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); ++i)
            reverse(A[i].begin(), A[i].end());

        for(int i = 0; i < A.size(); ++i)
            for(int j = 0; j < A[0].size();++j)
                A[i][j] = 1 - A[i][j];

        return A;
    }
};

int main(){
    Solution s;
    vector<vector<int>> A{{1,1,0},{1,0,1},{0,0,0}};

    auto ans = s. flipAndInvertImage(A);
    for(int i = 0; i < ans.size();++i){
        for(int j = 0; j < ans[0].size(); ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}
