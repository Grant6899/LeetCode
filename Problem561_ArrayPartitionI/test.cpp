/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 27 21:14:07 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();++i)
            if(i & 1)
                res += min(nums[i-1], nums[i]);
        return res;
    }
};

int main(){
    vector<int> nums {1,4,2,3};
    Solution s;
    cout << s.arrayPairSum(nums) << endl;

    return 0;
}
