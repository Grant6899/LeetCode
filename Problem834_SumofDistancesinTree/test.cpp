/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 18:06:06 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> neibors(N, vector<int>());
        for(auto& e: edges){
            neibors[e[0]].push_back(e[1]);
            neibors[e[1]].push_back(e[0]);
        }
        vector<int> res(N), child(N);
		vector<bool> visited(N, false);

		dfs(neibors, 0, 0, child, visited, res, N);
		visited = vector<bool>(N, false);
		dfs_2(neibors, 0, child, visited, res, N);

        return res;
    }

	void dfs(vector<vector<int>>& neibors, int root, int dis, vector<int>& child, vector<bool>& visited, vector<int>& res, int N){
		visited[root] = true;
		res[0] += dis++;

		for(int neibor : neibors[root]){
			if(visited[neibor]) continue;
			dfs(neibors, neibor, dis, child, visited, res, N);
			child[root] += child[neibor];
		}
		child[root] += 1;
	}

	void dfs_2(vector<vector<int>>& neibors, int root, vector<int>& child, vector<bool>& visited, vector<int>& res, int N){
		visited[root] = true;
		for(int neibor : neibors[root]){
			if(visited[neibor]) continue;
			res[neibor] = res[root] - child[neibor] + N - child[neibor];
			dfs_2(neibors, neibor, child, visited, res, N);
		}
	}

};


int main(){
    Solution s;
    vector<vector<int>> edges{{0,1},{0,2},{2,3},{2,4},{2,5}};
    auto ans = s. sumOfDistancesInTree(6, edges);
    for(int a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}
