#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		for (int i = 0; i < matrix.size() / 2; i++)
			swap(matrix[i], matrix[matrix.size() - i - 1]);

		for (int i = 0; i< matrix.size(); i++) {
			for (int j = i + 1; j<matrix[i].size(); j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}


	}
};

int main() {

	Solution s;

	vector<vector<int>> mat = { {5,1,9,11},
							  {2,4,8,10},
							  {13,3,6,7},
							  {15,14,12,16} };

	 s.rotate(mat);

	return 0;

}