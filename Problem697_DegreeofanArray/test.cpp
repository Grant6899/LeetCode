/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  9 19:16:16 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> count; // count[i] = {cnt, st, ed};

		int deg = 0;

		for(int i = 0; i < nums.size(); ++i){
			if(count.find(nums[i]) == count.end())
				count[nums[i]] = {1, i, i};
			else{
				count[nums[i]][0]++;
				count[nums[i]][2] = i;
			}
            deg = max(deg, count[nums[i]][0]);
		}

		int res = INT_MAX;
        //cout << deg << endl;
		for(auto ele : count)
			if(ele.second[0] == deg)
				res = min(res, ele.second[2] - ele.second[1] + 1);

		return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{1, 2, 2, 3, 1};

    cout << s. findShortestSubArray(nums) << endl;
    return 0;
}

