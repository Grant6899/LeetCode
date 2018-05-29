/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:03:06 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string expr;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                expr += "/";
            }
            if (i == 1 && n > 2) {
                expr += "(";
            }
            expr += to_string(nums[i]);
            if (i == n - 1 && n > 2) {
                expr += ")";
            }
        }
        return expr;
    }
};

int main(){
    Solution s;
    vector<int> nums{1000, 100, 10, 2};
    cout << s.optimalDivision(nums) << endl;
    return 0;
}
