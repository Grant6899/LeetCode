/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 18:59:14 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        _nums = nums;
    }

    int pick(int target) {
		vector<int> idx;
        for(int i = 0; i < _nums.size();++i)
			if(_nums[i] == target)
				idx.push_back(i);

		int res = idx[rand() % idx.size()];
		return res;
    }

private:
	vector<int> _nums;
};

int main(){
    vector<int> nums{1,3,4,12,3,4,4,4,4};
    Solution s(nums);
    cout << s.pick(4) << endl;
    return 0;
}
