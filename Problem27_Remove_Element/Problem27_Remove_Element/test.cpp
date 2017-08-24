#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;



class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int cnt = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == val)
				cnt++;
			else
				nums[i - cnt] = nums[i];
		}
		return nums.size() - cnt;
	}
};


int main() {
	Solution s;


	vector<int> src{3,2,2,3};


	auto ans = s.removeElement(src, 3);

	return 0;
}