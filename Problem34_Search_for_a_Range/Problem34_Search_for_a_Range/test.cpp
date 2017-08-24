#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {

		int left = findleft(nums, target, 0, nums.size()-1);
		int right = findright(nums, target, left, nums.size() - 1);

		vector<int> res;
		res.push_back(left);
		res.push_back(right);

		return res;
	}

	int findleft(vector<int>& nums, int target, int l, int r){
		if (l > r)
			return l;




		return 0;

	}

	int findright(vector<int>& nums, int target, int l, int r){
		return 0;
	}



};

int main() {
	Solution s;


	vector<int> vec = {5, 7, 7, 8, 8, 10};
	auto ans = s.searchRange(vec, 8);

	return 0;
}