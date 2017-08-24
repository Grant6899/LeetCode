#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		int result = 0;

		for (int i = 0; i < nums.size(); i++) {

			if (nums[i] == target)
				return i;

			if (target > nums[i])
				result = i + 1;

		}
		return result;

	}
};


int main() {
	Solution s;


	vector<int> vec = {  };
	auto ans = s.searchInsert(vec, 0);

	std::cout << ans << std::endl;


	return 0;
}