#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {

		vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));

		sum[1][1] = 1;

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (i != 1 || j != 1)
					sum[i][j] = sum[i - 1][j] + sum[i][j - 1];

		return sum[m][n];
	}
};


int main() {
	Solution s;

	std::cout << s.uniquePaths(36, 7) << std::endl;
	
	return 0;
}