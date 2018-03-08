/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  8 18:42:12 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.empty() || nums[0].empty())
            return nums;

        if(nums.size() * nums[0].size() != r * c)
            return nums;


        vector<vector<int>> res(r, vector<int>(c));

        for(int i = 0; i < nums.size(); ++i)
            for(int j = 0; j < nums[0].size(); ++j){
                int order = i * nums[0].size() + j;
                //cout << order << endl;
                //cout << order/c << " " << order % c << endl;
                res[order / c][order % c] = nums[i][j];
            }

        return res;
    }
};

int main(){
    vector<vector<int>> mat{{1,2,3,4}};
    Solution s;
    auto ans = s.matrixReshape(mat, 2, 2);
    return 0;
}
