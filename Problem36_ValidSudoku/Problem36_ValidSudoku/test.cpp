#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		vector<vector<set<char>>> block(3, vector<set<char>>(3, set<char>()));
		vector<set<char>> row(9, set<char>());
		vector<set<char>> col(9, set<char>());
        set<char> dia1, dia2;    

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					continue;
                else{
                    
                    if(block[i/3][j/3].find(board[i][j]) == block[i/3][j/3].end())
                        block[i/3][j/3].insert(board[i][j]);
                    else 
                        return false;
                        
                    if(row[i].find(board[i][j]) == row[i].end())
                        row[i].insert(board[i][j]);
                    else 
                        return false;

                    if(col[j].find(board[i][j]) == col[j].end())
                        col[j].insert(board[i][j]);
                    else 
                        return false;

                    if(i == j && dia1.find(board[i][j]) == dia1.end())
                        dia1.insert(board[i][j]);
                    else 
                        return false;

                    if(i + j == 8 && dia2.find(board[i][j]) == dia2.end())
                        dia2.insert(board[i][j]);
                    else 
                        return false;
                }
            }
        }
        return true;
	}
};

int main() {

	Solution s;

	vector<vector<char>> map   { {'.','8','7','6','5','4','3','2','1'},
                       {'2','.','.','.','.','.','.','.','.'},
                       {'3','.','.','.','.','.','.','.','.'},
                       {'4','.','.','.','.','.','.','.','.'},
                       {'5','.','.','.','.','.','.','.','.'},
                       {'6','.','.','.','.','.','.','.','.'},
                       {'7','.','.','.','.','.','.','.','.'},
                       {'8','.','.','.','.','.','.','.','.'},
                       {'9','.','.','.','.','.','.','.','.'}};

	cout << s.isValidSudoku(map) << endl;

	return 0;

}
