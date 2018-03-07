/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 19:01:22 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

		unordered_map<int, int> seen;

		seen[0] = -1;

		int sum = 0, max_len = 0;
		for(int i = 0; i < nums.size(); ++i){
			sum += nums[i] == 1? 1 : -1;

			if(seen.find(sum) == seen.end())
				seen[sum] = i;
			else
				max_len = max(i - seen[sum], max_len);
		}
		return max_len;
    }
};


int main(){
    vector<int> nums{1, 0, 1, 1};
    Solution s;
    cout << s.findMaxLength(nums) << endl;
    return 0;
}

