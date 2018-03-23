/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 22 19:42:33 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0, N = nums.size();

		sort(nums.begin(), nums.end());

		for(int i = 0; i < N - 2; ++i){
			int left = i + 1;
			int right = N - 1;
			while(left < right){

				if(nums[i] + nums[left] + nums[right] < target){
					res += right - left;
					left++;
				}
				else
					right--;
			}
		}
		return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{-2, 0, 1, 3};
    cout << s. threeSumSmaller(nums, 2) << endl;
    return 0;
}
