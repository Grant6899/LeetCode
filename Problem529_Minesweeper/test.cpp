/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 14 14:40:22 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        reveal(board, click[0], click[1]);
        return board;
    }
    
    void reveal(vector<vector<char>>& board, int i, int j){
        if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'E'){
            
            if(board[i][j] != 'M'){
                int mines = countMines(board, i, j);
                if(mines == 0){
                    board[i][j] = 'B';
                    reveal(board, i-1, j-1);
                    reveal(board, i-1, j);
                    reveal(board, i-1, j+1);
                    reveal(board, i, j-1);
                    reveal(board, i, j+1);
                    reveal(board, i+1, j-1);
                    reveal(board, i+1, j);
                    reveal(board, i+1, j+1);

                }
                else
                    board[i][j] = (char)('0' + mines);
            }

        }
    }
    
    int countMines(vector<vector<char>>& board, int i, int j){
        int res = 0;
        for(int ii = -1; ii <= 1; ++ii)
            for(int jj = -1; jj <= 1; ++jj)
                if(!(ii == 0 && jj == 0) && i + ii >= 0 && i + ii < board.size() && j + jj>= 0 && j + jj< board[0].size() && board[i+ii][j+jj] == 'M')
                    res++;
        return res;
    }
};

int main(){
    vector<vector<char>> map {{'E', 'E', 'E', 'E', 'E'},
                              {'E', 'E', 'M', 'E', 'E'},
                              {'E', 'E', 'E', 'E', 'E'},
                              {'E', 'E', 'E', 'E', 'E'}};
    
    vector<int> click {3, 0};
    Solution s;

    auto ans = s.updateBoard(map, click);
    click = vector<int> {1, 2};
    ans = s.updateBoard(map, click);
    for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map[0].size(); ++j){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
