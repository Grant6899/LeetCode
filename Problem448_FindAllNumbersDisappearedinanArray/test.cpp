/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:36:29 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

		for(int i = 0; i < nums.size(); ++i){
			int index = abs(nums[i]) - 1;
			if(nums[index] > 0) nums[index] = -nums[index];
		}

		vector<int> res;
		for(int i = 0; i < nums.size(); ++i)
			if(nums[i]>0)
				res.push_back(i+1);

		return res;
    }
};

int main(){
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution s;
    auto ans = s.findDisappearedNumbers(nums);
    for(int a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}
