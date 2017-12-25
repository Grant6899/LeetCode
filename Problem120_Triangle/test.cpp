/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 24 17:26:52 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; --i){
            for (int j = 0; j < triangle[i].size(); ++j)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
        return triangle[0][0];
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec{
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << s.minimumTotal(vec) << endl;
    for(int i = 0; i < vec.size();++i){
        for(int j = 0; j < vec[i].size(); ++j)
            cout << vec[i][j] << "|";
        cout << endl;
    }
    return 0;
}
