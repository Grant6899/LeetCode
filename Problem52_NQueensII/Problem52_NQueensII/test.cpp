#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		this->col = vector<bool>(n, true);
		this->row = vector<bool>(n, true);
		this->dia1 = vector<bool>(2 * n - 1, true);
		this->dia2 = vector<bool>(2 * n - 1, true);
		this->num = n;

		find(0);

		return result;

	}

private:
	void find(int next) {
		if (next == num) {
			result++;
			return;
		}

		for (int i = next; i < num; ++i)
			if (row[i] && ((i > 0 && !row[i - 1]) || i == 0))
				for (int j = 0; j < num; ++j)
					if (col[j]) {
						if (dia1[i + j] && dia2[num + i - j - 1]) {
							row[i] = false;
							col[j] = false;
							dia1[i + j] = false;
							dia2[num + i - j - 1] = false;
							find(next + 1);
							row[i] = true;
							col[j] = true;
							dia1[i + j] = true;
							dia2[num + i - j - 1] = true;
						}
					}
	}

	vector<bool> row, col, dia1, dia2;
	int result = 0;
	int num;

};


int main() {
	Solution s;

	auto ans = s.totalNQueens(8);

	return 0;
}