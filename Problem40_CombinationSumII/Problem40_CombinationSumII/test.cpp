#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		this->target = target;
		this->candidates = candidates;
		this->used = vector<bool>(candidates.size(), false);

		std::sort(this->candidates.begin(), this->candidates.end());

		find(0);
		return result;
	}

private:
	vector<vector<int>> result{};
	int target;
	int sum = 0;
	vector<int> current{}, candidates{};
	vector<bool> used;


	void find(int next) {
		if (sum == target) {
			result.push_back(current);
			return;
		}
		else if (sum > target)
			return;

		
		for (int i = 0; i < candidates.size(); i++) {
			if (!used[i]) {
				if (i + 1 < candidates.size() && candidates[i] == candidates[i + 1] && used[i+1] == false)
					continue;
				if ((next > 0 && candidates[i] >= current.back()) || next == 0) {
					sum += candidates[i];
					current.push_back(candidates[i]);
					used[i] = true;
					find(next + 1);
					used[i] = false;
					current.pop_back();
					sum -= candidates[i];
				}
				
			}

		}
		return;
	}
};

int main() {

	Solution s;

	vector<int> c{ 10,1,2,7,6,1,5 };

	auto ans = s.combinationSum2(c, 8);

	return 0;

}