/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 19 22:32:07 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> res;
        vector<bool> oncircle(graph.size(), false);
        vector<bool> visited(graph.size(), false);

        for(int i = 0; i < graph.size(); ++i){
            vector<bool> onpath(graph.size(), false);
            if(!oncircle[i] && !dfs(i, onpath, graph, oncircle, visited))
                res.push_back(i);
            else
                oncircle[i] = true;
        }
        return res;
    }


    bool dfs(int i, vector<bool>& onpath, vector<vector<int>>& graph, vector<bool>& oncircle, vector<bool>& visited){
        onpath[i] = true;
        visited[i] = true;
        for(int neibor : graph[i]){
            if(oncircle[neibor] || onpath[neibor])
                return true;
            if(visited[neibor])
                continue;
            if(dfs(neibor, onpath, graph, oncircle, visited)){
                oncircle[neibor] = true;
                return true;
            }
        }

        onpath[i] = false;
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph{{1,2},{2,3},{5},{0},{5},{},{}};
    auto ans = s. eventualSafeNodes(graph);
    for(auto a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}
