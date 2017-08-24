#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() <= 2) return{};

		int gap = INT_MAX;
		int result;

		std::sort(nums.begin(), nums.end());
		
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int left = i + 1, right = nums.size() - 1;

			while (left < right) {
				if (nums[i] + nums[left] + nums[right] - target == 0) {
					return target;
				}
				else if (nums[i] + nums[left] + nums[right] - target > 0) {
					
					if (abs(nums[i] + nums[left] + nums[right] - target) < gap) {
						gap = abs(nums[i] + nums[left] + nums[right] - target);
						result = nums[i] + nums[left] + nums[right];
					}
						
					do {
						right--;
					} while (nums[right] == nums[right + 1]);
				}
				else {

					if (abs(nums[i] + nums[left] + nums[right] - target) < gap) {
						gap = abs(nums[i] + nums[left] + nums[right] - target);
						result = nums[i] + nums[left] + nums[right];
					}

					do {
						left++;
					} while (nums[left] == nums[left - 1]);
				}
			}
		}

		return result;
	}
};

int main() {
	Solution s;
	std::vector<int> data = { 0, 1, 2 };
	std::cout << s.threeSumClosest(data, 3) << std::endl;

	return 0;
}