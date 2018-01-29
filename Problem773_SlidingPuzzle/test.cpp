/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 27 22:04:45 2018
 ************************************************************************/

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

struct stage{
    string board;
    int r0, c0, step;
    stage(string str, int r, int c, int st) : board(str), r0(r), c0(c), step(st) {}
};

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> visited;
        
        visited.insert(encodeBoard(board));

        if(encodeBoard(board) == "123450")
            return 0;

        int r0 = 0, c0 = 0;
         for(int i = 0; i <= 1; ++i)
            for(int j = 0; j <= 2; ++j)
                if(board[i][j] == 0){
                    r0 = i; 
                    c0 = j;
                }

        int res = INT_MAX, step = 0;
        bool find = false;

        vector<stage> prev, current;

        current.push_back(stage(encodeBoard(board), r0, c0, 0));



        while(!(current.size() == prev.size() || find == true)){
            prev = current;
            step++;

            for(stage s : prev){
                for(int i = 0; i < 4; ++i){
                    string str = s.board;
                    int r0 = s.r0, c0 = s.c0;
                    if(i == 0 && checkRange(r0 - 1, c0)){
                        swap(str[(r0 - 1)*3 + c0], str[r0*3 + c0]);
                        if(!visited.count(str)){
                            visited.insert(str);
                            current.push_back(stage(str, r0 - 1, c0, step));
                            if(str == "123450"){
                                res = step;
                                find = true;
                            }
                        }
                    }
                    else if(i == 1 && checkRange(r0 + 1, c0)){
                        swap(str[(r0 + 1)*3 + c0], str[r0*3 + c0]);
                        if(!visited.count(str)){
                            visited.insert(str);
                            current.push_back(stage(str, r0 + 1, c0, step));
                            if(str == "123450"){
                                res = step;
                                find = true;
                            }
                        }
                    }
                    else if(i == 2 && checkRange(r0, c0 - 1)){
                        swap(str[r0*3 + c0 - 1], str[r0*3 + c0]);
                        if(!visited.count(str)){
                            visited.insert(str);
                            current.push_back(stage(str, r0, c0 - 1, step));
                            if(str == "123450"){
                                res = step;
                                find = true;
                            }
                        }
                    }
                    else if(i == 3 && checkRange(r0, c0 + 1)){
                        swap(str[r0*3 + c0 + 1], str[r0*3 + c0]);
                        if(!visited.count(str)){
                            visited.insert(str);
                            current.push_back(stage(str, r0, c0 + 1, step));
                            if(str == "123450"){
                                res = step;
                                find = true;
                            }
                        }
                    }
                }
            }
        }
        return res == INT_MAX? -1 : res;
    }
    
    
    bool checkRange(int i, int j){
        return (i >= 0 && i <= 1 && j >=0 && j <= 2);
    }
    
    string encodeBoard(vector<vector<int>>& board){
        string res = "";
        for(int i = 0; i <= 1; ++i)
            for(int j = 0; j <= 2; ++j)
                res += to_string(board[i][j]);
        return res;
    }
    
};


int main(){
    
    vector<vector<int>> map{{4,1,2}, {5,0,3}};

    Solution s;

    cout << s.slidingPuzzle(map) << endl;

    return 0;
}
