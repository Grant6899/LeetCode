#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		if (nums.size() == 0)
			return;
		subsum = vector<int>(nums.size(), 0);
		subsum[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) 
			subsum[i] = subsum[i - 1] + nums[i];
	}

	int sumRange(int i, int j) {
		int temp;
		if (i == 0)
			temp = 0;
		else
			temp = subsum[i - 1];

		return subsum[j] - temp;
	}

private:
	vector<int> subsum;
};


int main() {
	
	vector<int> nums{ -2, 0, 3, -5, 2, -1 };

	NumArray obj(nums);
	int param_1 = obj.sumRange(2, 3);

	std::cout << param_1 << std::endl;

	return 0;
}