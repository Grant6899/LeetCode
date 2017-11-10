#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {

		if (nums.size() == 1)
			return 0;

		int max = 0, result = 0, curEnd = 0;

		for (int i = 0; i < nums.size() - 1; i++) {
				if (i <= max && i + nums[i] > max) 
					max = i + nums[i];
				
				if (i == curEnd) {
					result++;
					curEnd = max;
				}
		}


		return result;
	}
};

int main() {
	Solution s;

	vector<int> map{ 2,3,1,0,4};

	auto ans = s.jump(map);

	return 0;
}