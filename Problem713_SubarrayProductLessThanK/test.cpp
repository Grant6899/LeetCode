/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:47:30 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if( k== 0)
            return 0;
		int pro = 1, res = 0;
		for(int left = 0, right = 0; right < nums.size(); ++right){
			pro *= nums[right];
			while(left <= right && pro >= k){
				pro /= nums[left];
                left ++;
			}
			res += right - left + 1;
		}
		return res;
    }
};

int main(){
    vector<int> nums{10, 5, 2, 6};
    Solution s;
    cout << s.numSubarrayProductLessThanK(nums, 10) << endl;
}
