#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;


class Solution {
public:
	void nextPermutation(vector<int>& nums) {

		int axis = -1;
		for (int i = nums.size() - 1; i > 0; i--) {
			
			if (i > 0 && nums[i - 1] < nums[i]) {
				axis = i - 1;

				int axis2 = 0, dis = INT_MAX;
				for (int j = axis + 1; j < nums.size(); j++)
					if (nums[j] > nums[axis] && nums[j] - nums[axis] < dis) {
						axis2 = j;
						dis = nums[j] - nums[axis];
					}

				
				swap(axis, axis2, nums);
				break;
			}
		}

		for (int j = axis + 1; j < nums.size() - 1; j++)
			for (int k = j + 1; k < nums.size(); k++) {
				if (nums[j] > nums[k])
					swap(j, k, nums);
			}
			
	}


	void swap(int a, int b, vector<int>& vec) {
		int temp = vec[a];
		vec[a] = vec[b];
		vec[b] = temp;
	}


};

int main() {
	Solution s;

	vector<int> src{ 1, 2, 4, 3};

	s.nextPermutation(src);

	return 0;
}