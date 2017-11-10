#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		this->candidates = nums;
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int>> result{};

		for (int i = 0; i <= nums.size(); i++)
			combine(i, result);

		return result;
	}

	void combine(int k, vector<vector<int>>& result) {
		this->length = k;
		find(0, result, 0);
	}

	void find(int step, vector<vector<int>>& result, int lastidx) {
		if (current.size() == length) {
			result.push_back(current);
			return;
		}
		int start;
		if (current.size())
			start = lastidx + 1;
		else
			start = 0;
		for (int i = start; i < candidates.size(); i++) {
			current.push_back(candidates[i]);
			find(step + 1, result, i);
			current.pop_back();
		}
	}

private:
	int length;
	vector<int> current{}, candidates;

};

int main() {

	Solution s;

	vector<int> c{ 3,9 };

	auto ans = s.subsets(c);

	return 0;

}*