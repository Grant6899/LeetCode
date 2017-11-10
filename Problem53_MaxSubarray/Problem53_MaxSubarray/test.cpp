#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int result = nums[0], total = nums[0];

		for (int i = 1; i < nums.size(); ++i) {
			total += nums[i];
			if (total < nums[i])
				total = nums[i];
			if (total > result)
				result = total;
		}

		return result;

	}
};

int main() {
	Solution s;

	vector<int> x = { 1,2 };
	auto ans = s.maxSubArray(x);

	return 0;
}