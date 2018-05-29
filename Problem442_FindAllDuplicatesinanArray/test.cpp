/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:34:44 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> res;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[abs(nums[i]) - 1] < 0)
                res.push_back(abs(nums[i]));
            nums[abs(nums[i]) - 1] *= -1;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{4,3,2,7,8,2,3,1};
    auto ans = s.findDuplicates(nums);
    return 0;
}
