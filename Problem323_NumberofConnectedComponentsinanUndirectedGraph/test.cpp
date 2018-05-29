/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:43:18 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> neibor(n);

        for(auto edge : edges){
            neibor[edge.first].insert(edge.second);
            neibor[edge.second].insert(edge.first);
        }

        vector<bool> visited(n, false);

        int res = n;

        for(int i = 0; i < n; i++){
            if(!visited[i])
                dfs(i, res, visited, neibor);
        }
        return res;
    }

    void dfs(int cur, int& res, vector<bool>& visited, vector<unordered_set<int>>& neibor){
        //cout << "visiting " << cur << endl;
        visited[cur] = true;
        for(int i : neibor[cur]){
            if(!visited[i]){
                res--;
                dfs(i, res, visited, neibor);
            }
        }
    }
};

int main(){
    Solution s;
    vector<pair<int, int>> edges{{0,1},{1,2},{3,4}};
    cout << s.countComponents(5, edges) << endl;
    return 0;
}
