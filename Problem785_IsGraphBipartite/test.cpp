/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 09:45:03 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> painted(graph.size(), 0);

        for(int i = 0; i < graph.size(); ++i)
            if(!painted[i] && !paint(i, 1, graph, painted))
                return false;
        return true;
    }

    bool paint(int i, int color, vector<vector<int>>& graph, vector<int>& painted){
        if(painted[i]){
            if(painted[i] != color)
                return false;
            else
                return true;
        }
        else
            painted[i] = color;

        for(int next : graph[i])
            if(!paint(next, color == 1? 2 : 1, graph, painted))
                return false;

        return true;
    }

};

int main(){
    vector<vector<int>> graph{{1,2,3},{0,2},{0,1,3},{0,2}};
    Solution s;
    cout << s.isBipartite(graph) << endl;
    return 0;
}
