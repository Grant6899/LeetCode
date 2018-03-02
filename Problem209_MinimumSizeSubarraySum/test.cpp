/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:49:48 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int left = 0, right = 0;
		int sum = 0, res = INT_MAX;
		while(right < nums.size()){

			sum += nums[right];

			if(sum >= s){
				while(sum >= s){
                    res = min(right - left + 1, res);
                    //cout << left <<' ' << right << ' ' << sum << endl;
					sum -= nums[left];
					left++;
				}

			}
			right++;
		}

		if(res == INT_MAX) return 0;
		else return res;
    }
};

int main(){
    vector<int> nums{2,3,1,2,4,3};
    Solution s;
    cout << s.minSubArrayLen(7, nums) << endl;
    return 0;
}

