/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 21:09:37 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size();++i)
        for(int j = i + 1; j < nums.size(); ++j){
            res += hammingDistance(nums[i], nums[j]);
        }
        return res;
    }    
    
    int hammingDistance(int x, int y) {
        int n = x ^ y;

        // check bit 1 in n
        n = ((n & 0xAAAAAAAA) >> 1) + (n & 0x55555555);
        n = ((n & 0xCCCCCCCC) >> 2) + (n & 0x33333333);
        n = ((n & 0xF0F0F0F0) >> 4) + (n & 0x0F0F0F0F);
        n = ((n & 0xFF00FF00) >> 8) + (n & 0x00FF00FF);
        n = ((n & 0xFFFF0000) >> 16) + (n & 0x0000FFFF);
        return n;
    }
};

int main(){
    Solution s;
    vector<int> nums {14, 4, 2};

    cout << s.totalHammingDistance(nums) << endl;

    return 0;
}
