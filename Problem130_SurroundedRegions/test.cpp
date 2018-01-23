/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 22 21:09:47 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;

        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                if(i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1)
                    flip(i, j, board);

        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                if(board[i][j] == 'O') board[i][j] = 'X';

        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                if(board[i][j] == '*') board[i][j] = 'O';
    }

    void flip(int i, int j, vector<vector<char>>& board){
        if( i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        
        if(board[i][j] == 'O'){
            board[i][j] = '*';
            flip(i-1, j, board);
            flip(i+1, j, board);
            flip(i, j-1, board);
            flip(i, j+1, board);
        }
    }

};

int main(){
    vector<vector<char>> board {{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}};

    Solution s;

    s.solve(board);

    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    
    return 0;
}
