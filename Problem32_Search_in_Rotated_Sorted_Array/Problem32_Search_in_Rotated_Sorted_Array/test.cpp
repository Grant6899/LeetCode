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
	int search(vector<int>& nums, int target) {

		int left = 0, right = nums.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target) return mid;
			
			if (nums[left] <= nums[mid])
				if (nums[left] <= target && target <= nums[mid]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			if (nums[mid] <= nums[right])
				if (nums[mid] <= target && target <= nums[right]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
		}
		return -1;
	}
};

int main() {
	Solution s;
	vector<int> vec = { 1, 2, 3, 7, 8, 9, -1, 0 };
	std::cout << s.search(vec, 7) << std::endl;
	return 0;
}