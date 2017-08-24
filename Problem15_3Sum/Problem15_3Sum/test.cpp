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
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() <= 2) return{};
		vector<vector<int>> result;

		std::sort(nums.begin(), nums.end());
		

		for (int i = 0; i < nums.size() - 2; i++) {
			if ( i > 0 && nums[i] == nums[i - 1]) continue;
			int left = i + 1, right = nums.size() - 1;

			while (left < right) {
				if (nums[i] + nums[left] + nums[right] == 0) {
					result.push_back({ nums[i], nums[left], nums[right] });
					do {
						left++;
					} while (nums[left] == nums[left - 1]);
					do {
						right--;
					} while (nums[right] == nums[right + 1]);
				}
				else if (nums[i] + nums[left] + nums[right] > 0) {
					do {
						right--;
					} while (nums[right] == nums[right + 1]);
				}
				else {
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
	std::vector<int> data = { -2,0,0,2,2 };
	auto ans = s.threeSum(data);

	return 0;
}