#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int sum = 0;
		for (auto it = prices.begin(); it < prices.end() - 1; ++it) {
			if (*it < *(it + 1))
				sum += *(it + 1) - *(it);
		}
		return sum;
	}
};

int main() {

	vector<int> p = { 7, 9 ,3 ,5, 6 };

	Solution s;

	std::cout << s.maxProfit(p) << std::endl;

	return 0;
}