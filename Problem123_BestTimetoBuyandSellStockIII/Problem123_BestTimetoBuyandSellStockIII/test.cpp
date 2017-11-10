#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {

		vector<vector<int>> s(2 * k, vector<int>(2, 0));

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2 * k; j++)
				if (j % 2 == 0)
					s[j][i] = INT_MIN;

		int current = 0, next = 1;
		for (int i = 1; i <= prices.size(); i++) {
			for (int j = 0; j < 2 * k; j++) {
				if (j == 0)
					s[0][next] = max(s[0][current], -prices[0]);
				else if (j % 2 == 1)
					s[j][next] = max(s[j][current], s[j - 1][current] + prices[i - 1]);
				else if (j % 2 == 0)
					s[j][next] = max(s[j][current], s[j - 1][current] - prices[i - 1]);
			}
			swap(next, current);
		}


		int maxx = INT_MIN;

		for (int j = 0; j < 2 * k; j++)
			if (j % 2 == 1 && s[current][prices.size()] > maxx)
				maxx = s[j][current];

		return maxx;
	}
};

int main() {
	Solution s;

	vector<int> map{ 3,1,2,4,5 };

	std::cout << s.maxProfit(2, map)<< std::endl;
}