/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:13:02 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res(M.size(), vector<int>(M[0].size(), 0));

        for(int i = 0; i < M.size(); ++i)
            for(int j = 0;j < M[0].size(); ++j){
                int cnt = 1, sum = M[i][j];
                for(int k = 0; k < 8; ++k)
                    if(0 <= i + delta[k][0] && i + delta[k][0] < M.size() &&
                       0 <= j + delta[k][1] && j + delta[k][1] < M[0].size()){
                        cnt ++;
                        sum += M[i + delta[k][0]][j + delta[k][1]];
                    }
                    /*cout << "(" << i << ", " << j << ")\n";
                    cout << "cnt: " << cnt << endl;
                    cout << "sum: " << sum << endl;*/
                    res[i][j] = floor(sum / (double)cnt);
            }
        return res;
    }

    vector<vector<int>> delta{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
};

int main(){
    Solution s;
    vector<vector<int>> M{{1,1,1},{1,0,1}, {1,1,1}};
    auto res = s.imageSmoother(M);
}
