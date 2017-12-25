/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 24 17:06:00 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0)
            return result;

        result = {{1}};
        for(int i = 1; i < numRows; ++i){
            vector<int> temp;
            for(int j = 0; j < i+1; ++j)
                temp.push_back(getValue(result, i-1, j-1) + getValue(result, i-1, j));
            result.push_back(temp);
        }
        return result;
    }

private:
    int getValue(const vector<vector<int>>& vec, int i, int j){
        if( 0 <= i && i < vec.size() && 0 <= j && j < vec[i].size())
            return vec[i][j];
        else
            return 0;
    }
};

int main(){
    Solution s;

    auto ans = s.generate(5);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << ", ";
        cout << endl;
    }
    return 0;
}
