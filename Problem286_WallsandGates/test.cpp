/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 18:43:28 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i = 0; i < rooms.size(); ++i)
			for(int j = 0; j < rooms[0].size(); ++j){
				if(rooms[i][j] == 0){
					dfs(0, i, j, rooms);
				}
			}
    }

	void dfs(int step, int i, int j, vector<vector<int>>& rooms){
		if(i >= 0 && i < rooms.size() && j >= 0 && j < rooms[0].size() && rooms[i][j] != -1){
			if(rooms[i][j] >= step){
				rooms[i][j] = step;
				dfs(step + 1, i - 1, j, rooms);
				dfs(step + 1, i + 1, j, rooms);
				dfs(step + 1, i, j - 1, rooms);
				dfs(step + 1, i, j + 1, rooms);
			}
		}
	}

};


int main(){
    Solution s;
    vector<vector<int>> rooms{{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    s.wallsAndGates(rooms);

    for(int i = 0; i < rooms.size(); ++i){
        for(int j : rooms[i])
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}
