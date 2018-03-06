/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:24:51 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;

		for(int n : nums){
			if(n <= min1)
				min1 = n;
			else if(n <= min2)
				min2 = n;
			else
				return true;
		}
		return false;
    }
};

int main(){
    vector<int> nums{1,3,4,-1};
    Solution s;
    cout << s.increasingTriplet(nums) << endl;
    return 0;
}
