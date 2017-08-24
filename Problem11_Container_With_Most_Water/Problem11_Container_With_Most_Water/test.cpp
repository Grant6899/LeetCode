#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1, maxVol = -1;

		while (left < right) {
			int low = height[left] > height[right] ? right : left;
			if (height[low] * (right - left) > maxVol)
				maxVol = height[low] * (right - left);
			
			if (low == left) left++;
			else right--;
		}

		return maxVol;
	}
};

int main() {
	Solution s;
	
	vector<int> h{ 1, 2, 1 };

	std::cout << s.maxArea(h) << std::endl;

	return 0;
}