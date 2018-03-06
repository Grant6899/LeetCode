/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:53:09 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int sum = 0;
		unordered_map<int, int> sumseen;
		sumseen[0]++;
		
		int res = 0;
		for(int i = 0; i < nums.size(); ++i){
			sum += nums[i];
			res += sumseen[sum - k];
			sumseen[sum]++;
		}
		return res;
    }
};

int main(){
    vector<int> nums{1,1,1};
    Solution s;
    cout << s.subarraySum(nums, 2) << endl;
    return 0;
}

