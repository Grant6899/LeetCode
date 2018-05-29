/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:04:58 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> cnt(5, vector<int>(9, 0));
		
		int res = 0;
		
		for(int i = nums.size() - 1; i >= 0; --i){
			
			int D = to_string(nums[i])[0] - '0';
			int P = to_string(nums[i])[1] - '0';
			int V = stoi(to_string(nums[i]).substr(2));
			
			if(cnt[D][P] == 0)
                cnt[D][P] = 1;
			
			if(D - 1 >= 1)
				cnt[D-1][(P + 1) / 2] += cnt[D][P];
			
			res += cnt[D][P] * V;
		}
		
		return res;
    }
};


int main() {
	Solution s;
	vector<int> nums{ 113,215,221};

	auto ans = s.pathSum(nums);
	cout << ans << endl;
	return 0;
}
