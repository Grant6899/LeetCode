#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		this->used = vector<bool>(nums.size(), false);
		this->target = nums.size();
		this->candidates = nums;
		std::sort(this->candidates.begin(), this->candidates.end());
		find(0);
		return result;
	}

	void find(int next) {
		if (current.size() == target) {
			result.push_back(current);
	        
            for(int ele : current)
                cout << ele << " ";
            cout << endl;
            return;
		}

		for (int i = 0; i< candidates.size(); i++)
			if (used[i] == false) {
				if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1])
					return;
				current.push_back(candidates[i]);
				used[i] = true;
				find(next + 1);
				used[i] = false;
				current.pop_back();
			}
	}

private:
	vector<int> current{};
	vector<bool> used;
	vector<int> candidates{};
	vector<vector<int>> result{};
	int target = 0;

};

int main() {

	Solution s;

	vector<int> map{ 1, 2, 2, 2, 3 };

	auto ans = s.permuteUnique(map);

	return 0;
}
