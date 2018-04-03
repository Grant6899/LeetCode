/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  2 22:48:58 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
		int x = 0;

		for(int n : nums)
			x ^= n;

		return x == 0 || nums.size() % 2 == 0;
    }
};

int main(){
    Solution s;
    vector<int> nums{1, 1, 2};
    cout << s. xorGame(nums) << endl;
    return 0;
}
