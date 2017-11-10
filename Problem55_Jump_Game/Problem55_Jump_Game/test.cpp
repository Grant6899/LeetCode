#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {

		int max = 0;
		for (int i = 0; i < nums.size() - 1; i++)
			if (i <= max && i + nums[i] > max)
				max = i + nums[i];

		return nums.size() - 1 <= max;

	}
};

int main() {
	Solution s;

	vector<int> map { 3,2,1,0,4 };

	std::cout << std::boolalpha << s.canJump(map) << std::endl;
	return 0;
}