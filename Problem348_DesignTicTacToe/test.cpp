/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  2 22:53:05 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<vector<int>>(n, vector<int>(3, 0));
		cols = vector<vector<int>>(n, vector<int>(3, 0));
		diag1 = vector<int>(3, 0);
		diag2 = vector<int>(3, 0);
		size = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        rows[row][player]++;
		if(rows[row][player] == size)
			return player;
		cols[col][player]++;
		if(cols[col][player] == size)
			return player;

        if(row == col){
            diag1[player]++;
            if(diag1[player] == size)
                return player;
        }

        if(row + col == size - 1){
            diag2[player]++;
            if(diag2[player] == size)
                return player;
        }

		return 0;
    }

	vector<vector<int>> rows, cols;
	vector<int> diag1, diag2;
	int size;
};

int main(){
    TicTacToe t(3);
    cout << t.move(0,0,1) << endl;
    return 0;
}
