#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {

		vector<vector<int>> sum(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
		for (int i = 1; i <= grid.size(); i++)
			for (int j = 1; j <= grid[0].size(); j++)
				if (i == 1 && j == 1)
					sum[i][j] = grid[i - 1][j - 1];
				else if (i == 1)
					sum[i][j] = grid[i - 1][j - 1] + sum[i][j - 1];
				else if (j == 1)
					sum[i][j] = grid[i - 1][j - 1] + sum[i - 1][j];
				else
					sum[i][j] = grid[i - 1][j - 1] + min(sum[i - 1][j], sum[i][j - 1]);

		return sum[grid.size()][grid[0].size()];
	}
};


int main() {
	Solution s;

	vector<vector<int>> map { {1, 2}, { 1,1 }};

	std::cout << s.minPathSum(map) << std::endl;

	return 0;
}