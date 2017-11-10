#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;

		int rownum = matrix.size(), colnum = matrix[0].size();
		
		int top = 0, bot = rownum - 1, mid = 0;

		if (target < matrix[0][0] || target > matrix[rownum-1][colnum-1])
			return false;

		while (top < bot) {
			
			if (matrix[top][0] == target || matrix[bot][0] == target)
				return true;

			mid = (top + bot) / 2;

			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0] > target)
				bot = mid - 1;
			else
				top = mid;
		}

		int left = 0, right = colnum - 1;

		if (target < matrix[top][0])
			return false;

		while (left < right) {

			if (matrix[top][left] == target || matrix[top][right] == target)
				return true;

			mid = (left + right) / 2;

			if (matrix[top][mid] == target)
				return true;
			else if (matrix[top][mid] > target)
				right = mid - 1;
			else
				left = mid;
		}

		return false;
	}
};

int main() {

	Solution s;

	vector<vector<int>> mat{
			{1, 3, 5, 7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}
	};

	std::cout << std::boolalpha<< s.searchMatrix(mat, 20) << std::endl;

	return 0;

}