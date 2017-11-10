#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {

		int leftH = 0, rightH = 0, left = 0, right = height.size() - 1;


		int total = 0, checkpoint = 0, sum = 0;

		for (int i = 0; i < height.size(); i++)
			sum += height[i];

		while (left <= right) {

			if (leftH == rightH) {
				while (left <= right && height[left] <= leftH)
					++left;
				if (left < height.size())
					leftH = height[left];

				while (left <= right && height[right] <= rightH)
					--right;
				if (right >= 0)
					rightH = height[right];
			}
			else if (leftH < rightH) {
				while (left <= right && height[left] <= leftH)
					++left;
				if (left < height.size())
					leftH = height[left];
			}
			else {
				while (left <= right && height[right] <= rightH)
					--right;
				if (right >= 0)
					rightH = height[right];
			}
			
			total += (min(leftH, rightH) - checkpoint) * (right - left + 1);
			checkpoint = min(leftH, rightH);

		}
		return total - sum;
	}
};
int main() {

	Solution s;

	vector<int> nums{ 1 };

	auto ans = s.trap(nums);

 	return 0;
}