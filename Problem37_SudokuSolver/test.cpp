#include<iostream>
#include<set>
#include<vector>
#include<utility>
using namespace std;

class Solution {
private:
    int count_fill = 0;
    vector<vector<set<char>>> block;
    vector<set<char>> row;
    vector<set<char>> col;
    vector<pair<int, int>> to_fill;

public:
    void solveSudoku(vector<vector<char>>& board) {

        block = vector<vector<set<char>>>(3, vector<set<char>>(3, set<char>()));
        row = vector<set<char>>(9, set<char>());
        col = vector<set<char>>(9, set<char>());

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    to_fill.push_back(make_pair(i, j));
                    count_fill++;
                }
                else {

                    if (block[i / 3][j / 3].find(board[i][j]) == block[i / 3][j / 3].end())
                        block[i / 3][j / 3].insert(board[i][j]);

                    if (row[i].find(board[i][j]) == row[i].end())
                        row[i].insert(board[i][j]);

                    if (col[j].find(board[i][j]) == col[j].end())
                        col[j].insert(board[i][j]);
                }
            }
        }

        fillSudoku(board, 0);

        return;
    }

    bool fillSudoku(vector<vector<char>>& board, int current) {
        if (current == count_fill)
            return true;

        for (char ch = '1'; ch < '1' + 9; ++ch) {
            int r = to_fill[current].first, c = to_fill[current].second;

            if (block[r / 3][c / 3].find(ch) == block[r / 3][c / 3].end() && row[r].find(ch) == row[r].end() && col[c].find(ch) == col[c].end()) {
                block[r / 3][c / 3].insert(ch);
                row[r].insert(ch);
                col[c].insert(ch);
                board[r][c] = ch;
                if (fillSudoku(board, current + 1))
                    return true; 
                block[r / 3][c / 3].erase(ch);
                row[r].erase(ch);
                col[c].erase(ch);
            }
        }
        return false;
    }
};


int main() {

	Solution s;
    
	vector<vector<char>> map {{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
	s.solveSudoku(map);

    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j)
            cout << map[i][j] <<"|";
        cout << endl;
    }

	return 0;
}
