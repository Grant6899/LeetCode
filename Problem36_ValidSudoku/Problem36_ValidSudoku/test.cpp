#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		vector<unordered_set<char>> maze;
		vector<unordered_set<char>> row;
		vector<unordered_set<char>> col;

		maze.reserve(9);
		row.reserve(9);
		col.reserve(9);

		for (int i = 0; i < 9; i++) {

			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.' && row[i].find(board[i][j]) != row[i].end())
					return false;
				else
					row[i].insert(board[i][j]);

				if (board[j][i] != '.' && col[i].find(board[j][i]) != col[i].end())
					return false;
				else
					col[i].insert(board[j][i]);
			}
		}
		return true;
	}
};

int main() {

	Solution s;

	char[9][9] map = { ".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........" };

	//auto ans = s.isValidSudoku(map);

	return 0;

}