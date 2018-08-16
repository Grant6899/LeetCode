/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jul  8 14:14:44 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
public:
    struct Node{
        int x, y, keys;
        Node(int xx, int yy, int k) : x(xx), y(yy), keys(k) {}
    };
    
    int shortestPathAllKeys(vector<string>& grid) {
        
        int key_cnt = 0;
        int st_i = 0, st_j = 0;
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j){
                if('a' <= grid[i][j] && grid[i][j] <= 'f')
                    key_cnt++;
                if(grid[i][j] == '@'){
                    st_i = i; st_j = j;
                }
            }
        
        vector<vector<vector<int>>> visited(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(pow(2, key_cnt), 0)));
        
        queue<Node> q;
        q.push(Node(st_i, st_j, 0));
        
        visited[st_i][st_j][0] = true;
        int step = 0;
        
        while(!q.empty()){
            step++;
            for(int i = 0; i < q.size(); ++i){
                Node cur = q.front();
                q.pop();
                
                cout << "step = " << step << " current node:\n(" << cur.x << ", " << cur.y << ") keys: " << cur.keys << endl << endl;
                
                for(int k = 0; k < 4; ++k){
                    int next_x = cur.x + d[k];
                    int next_y = cur.y + d[k + 1];
                    
                    if(next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || grid[next_x][next_y] == '#')
                        continue;
                    
                    //cout << "next: (" << next_x << ", " << next_y << ")\n ";

                    // if next cell is a key
                    int new_key = 0, next_key = cur.keys;
                    if('a' <= grid[next_x][next_y] && grid[next_x][next_y] <= 'f'){
                        new_key = (1 << (key_cnt - grid[next_x][next_y] + 'a' - 1));
                        next_key = new_key | cur.keys;
                    }
                                   
                    // if next cell is a lock
                    bool isLocked = false;
                    if('A' <= grid[next_x][next_y] && grid[next_x][next_y] <= 'F'){
                        int key = (cur.keys >> (key_cnt - grid[next_x][next_y] + 'A' - 1));
                        isLocked = !(key & 1);
                    }
                    
                    // check if next is a valid state
                    if(!visited[next_x][next_y][next_key] && !isLocked){
                        // check if all keys are collected
                        if(next_key == pow(2, key_cnt) - 1)
                            return step;
                        visited[next_x][next_y][next_key] = true;
                        q.push(Node(next_x, next_y, next_key));
                    }
                }
            }
        }
        return -1;
    }
    
private:
    vector<int> d {0, -1, 0, 1, 0};
};

int main(){
	Solution s;
	vector<string> grid{"@.a.#","###.#","b.A.B"};

	cout << s.shortestPathAllKeys(grid) << endl;
	return 0;
}
