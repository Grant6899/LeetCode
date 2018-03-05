/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 07:55:31 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));

        for(int i = 0; i < A.size(); ++i)
            for(int k = 0; k < A[i].size(); ++k){
                if(A[i][k]){
                    for(int j = 0; j < B[0].size(); ++j)
                        if(B[k][j]) res[i][j] += A[i][k] * B[k][j];
                }
            }
        return res;
    }
};

int main(){
    vector<vector<int>> A{{1,0,0}, {-1, 0, 3}}, B{{7,0,0}, {0,0,0},{0,0,1}};
    Solution s;
    auto ans = s.multiply(A, B);

    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[0].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
