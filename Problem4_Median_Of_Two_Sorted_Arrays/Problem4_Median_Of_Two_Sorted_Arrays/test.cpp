#include<iostream>
#include<vector>
#include<limits>

using namespace std;

class Solution {
public:

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		int total_len = nums1.size() + nums2.size();

		nums1.push_back(99999999);
		nums2.push_back(99999999);

		int i1 = -1;
		int i2 = -1;

		double cur;

		if (total_len % 2 != 0) {

			int target = (total_len + 1) / 2;

			for (int i = 0; i < target; ++i) {

				if (nums1[i1 + 1] <= nums2[i2 + 1]) {
					i1++;
					cur = nums1[i1];
				}
				else {
					i2++;
					cur = nums2[i2];
				}
			}
		}
		else {
			int target1 = (total_len) / 2;
			int target2 = target1 + 1;
			int l = 0;

			for (int i = 0; i < target2; ++i) {

				if (nums1[i1 + 1] <= nums2[i2 + 1]) {
					i1++;
					cur = nums1[i1];
				}
				else {
					i2++;
					cur = nums2[i2];
				}
				if (i == target1 - 1) l = cur;
			}
			cur = (l + cur) / 2.0;

		}
		return cur;
	}
};

int main() {

	std::vector<int> v1{ 1, 3, 4, 10, 13 }, v2{ };

	Solution s;
	std::cout << s.findMedianSortedArrays(v1, v2) << std::endl;


	return 0;
}