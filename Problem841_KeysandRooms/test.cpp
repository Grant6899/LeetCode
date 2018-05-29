/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:18:42 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms[0].empty())
            if(rooms.size() > 1) return false;
            else return true;
        return bfs(rooms);
    }
    
    bool bfs(vector<vector<int>>& rooms){
        queue<int> visited_rooms;
        visited_rooms.push(0);
        vector<bool> visited(rooms.size(), 0);
        visited[0] = true;
        int visited_cnt = 1;
        
        while(!visited_rooms.empty()){
            
            int cur_room = visited_rooms.front();
            visited_rooms.pop();
            
            for(int key : rooms[cur_room]){
                if(!visited[key]){
                    //cout << "visiting " << key << endl;
                    
                    visited[key] = true;
                    visited_cnt++;
                    visited_rooms.push(key);
                    
                    if(visited_cnt == rooms.size())
                        return true;
                }
            }
        }
        return false;        
       
    }
};

int main(){
    Solution s;
    vector<vector<int>> rooms{{1}, {2}, {3}, {}};
    cout << s. canVisitAllRooms(rooms) << endl;
    return 0;
}
