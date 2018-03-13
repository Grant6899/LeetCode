/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 12 23:47:50 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
		set<vector<pair<int, int>>> islands;
		
		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[0].size(); ++j){
				vector<pair<int, int>> island;
				dfs(i, j, 0, 0, island, grid);
				if(!island.empty()) 
                    islands.insert(norm(island));
			}
		return islands.size();
    }
	
	bool dfs(int i, int j, int m, int n, vector<pair<int, int>>& island, vector<vector<int>>& grid){
		if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
			return false;
		
		grid[i][j] = 0;
		island.push_back({m, n});
		
		for(int k = 0; k < 4; k++){
			dfs(i + delta[k][0], j + delta[k][1], m + delta[k][0], n + delta[k][1], island, grid);
		}
		
		return true;
	}
	
	vector<pair<int,int>> norm(vector<pair<int,int>> v) {
        vector<vector<pair<int,int>>> s(8);
        // compute rotations/reflections.
        for (auto p:v) {
            int x = p.first, y = p.second;
            s[0].push_back({x,y});
            s[1].push_back({x,-y});
            s[2].push_back({-x,y});
            s[3].push_back({-x,-y});
            s[4].push_back({y,-x});
            s[5].push_back({-y,x});
            s[6].push_back({-y,-x});
            s[7].push_back({y,x});
        }
        for (auto &l:s) sort(l.begin(),l.end());
        for (auto &l:s) {
            for (int i = 1; i < v.size(); ++i) 
                l[i] = {l[i].first-l[0].first, l[i].second - l[0].second};
            l[0] = {0,0};
        }
        sort(s.begin(),s.end());
        return s[0];
    }
    

private:
	vector<vector<int>> delta{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	
};

int main(){
    Solution s;
    vector<vector<int>> grid{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};

    cout << s.numDistinctIslands2(grid) << endl;
    return 0;
}

