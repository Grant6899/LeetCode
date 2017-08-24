#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		if (nums.size() < 4)
			return result;


		for (int i = 0; i < nums.size() - 3; i++){
			while (i > 0 && nums[i] == nums[i - 1])
				i++;

			for (int j = i + 1; j < nums.size() - 2; j++) {
				while (j > i + 1 && nums[j] == nums[j - 1])
					j++;
				int current = target - nums[i] - nums[j];

				int left = j + 1, right = nums.size() - 1;

				while (left < right) {
					if (current == nums[left] + nums[right]){
						result.push_back({ nums[i], nums[j], nums[left], nums[right] });
						do {
							left++;
						} while (left + 1 < nums.size() && nums[left] == nums[left - 1]);
						do {
							right--;
						} while (nums[right] == nums[right + 1]);
					}
					else if (current > nums[left] + nums[right]) {
						do {
							left++;
						} while (left + 1 < nums.size() && nums[left] == nums[left - 1]);
					}
					else if (current < nums[left] + nums[right]) {
						do {
							right--;
						} while (nums[right] == nums[right + 1]);
					}
			
				}
			}
		}
		return result;
	}
};

int main() {
	Solution s;

	vector<int> vec{-1,2,2,-5,0,-1,4 };

	auto ans = s.fourSum(vec, 3);

	return 0;
}