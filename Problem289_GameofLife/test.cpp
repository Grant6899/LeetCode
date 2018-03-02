/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:34:37 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> next = board;
		for(int i = 0; i < board.size(); ++i)
			for(int j = 0; j < board[0].size(); ++j){
				if(board[i][j] && countLive(board, i, j) < 2 || countLive(board, i, j) > 3) next[i][j] = 0;
				if(board[i][j] && countLive(board, i, j) == 2 || countLive(board, i, j) == 3) next[i][j] = 1;
				if(!board[i][j] && countLive(board, i, j) == 3) next[i][j] = 1;
			}

		board = next;
    }

	int countLive(vector<vector<int>>& board, int row, int col){
		int res = 0;
		for(int i = -1; i <= 1; ++i)
		for(int j = -1; j <= 1; ++j){
			if(i != 0 || j != 0){
				if(checkRange(board, row + i, col + j) && board[row+i][col+j]) res++;
			}
		}
		return res;
	}

	int checkRange(vector<vector<int>>& board, int i, int j){
		return (i >= 0 && i < board.size() && j >= 0 && j < board[0].size());
	}
};


int main(){
    vector<vector<int>> board;
    Solution s;
    s.gameOfLife(board);
    return 0;
}
