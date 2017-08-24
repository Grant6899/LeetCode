#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		for (int i = nums.size() - 1; i >= 1; i--) {
			if (nums[i] == nums[i - 1])
				nums.erase(nums.begin() + i);
		}

		return nums.size();
	}
};

int main() {

	Solution s;
	vector<int> data{ };

	std::cout << s.removeDuplicates(data) << std::endl;
	return 0;
}