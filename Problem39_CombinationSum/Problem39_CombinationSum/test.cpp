#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		this->target = target;
		this->candidates = candidates;

		std::sort(candidates.begin(), candidates.end());

		find(0);
		return result;
	}

private:
	vector<vector<int>> result {};
	int target;
	int sum = 0;
	vector<int> current{}, candidates{};
	

	void find(int next) {
		if (sum == target)
			result.push_back(current);
		else if (sum > target)
			return;
		
		for (int i = 0; i < candidates.size(); i++) {
			if (next == 0 || ( next > 0 && candidates[i] >= current[next - 1])) {
				sum += candidates[i];
				current.push_back(candidates[i]);
				find(next + 1);
				current.pop_back();
				sum -= candidates[i];
			}
			
		}
		return;
	}
};

int main() {

	Solution s;

	vector<int> c{ 2,3,6,7 };

	auto ans = s.combinationSum(c, 7);

	return 0;

}