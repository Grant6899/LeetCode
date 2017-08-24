#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int min = INT_MAX, maxprofit = 0;
		for (auto it = prices.begin(); it < prices.end(); ++it) {
			maxprofit = *it - min > maxprofit ? *it - min : maxprofit;
			if (*it < min) min = *it;
		}

		return maxprofit;
	}
};

int main() {

	Solution s;
	std::vector<int> p{ 7, 6, 4, 3, 1 };
	std::cout << s.maxProfit(p) << std::endl;
}