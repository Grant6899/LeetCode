/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 24 17:16:39 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> result;
        result = {1};

        if(numRows == 0)
            return result;

        for(int i = 1; i <= numRows; ++i){
            vector<int> temp;
            for(int j = 0; j < i+1; ++j)
                temp.push_back(getValue(result, j-1) + getValue(result, j));
            result = temp;
        }
        return result;
    }

private:
    int getValue(const vector<int>& vec, int i){
        if( 0 <= i && i < vec.size())
            return vec[i];
        else
            return 0;
    }
};

int main(){
    Solution s;

    auto ans = s.getRow(5);
    for(int i = 0; i < ans.size(); ++i){
            cout << ans[i] << ", ";
    }
    cout << endl;
    return 0;
}

