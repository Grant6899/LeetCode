/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Feb 24 07:13:18 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<queue>

using namespace std;  

struct Edge{
    int src, dst, weight;
    Edge(int _src, int _dst, int _weight) : src(_src), dst(_dst), weight(_weight) {}
};

vector<Edge> Prim(vector<vector<int>>& map, vector<vector<int>>& paths){
    unordered_set<int> visited{3};
    vector<Edge> res;
    int n = map.size();
    
    auto com = [](Edge a, Edge b){return a.weight > b.weight;};

    while(visited.size() != n){

        priority_queue<Edge, vector<Edge>, decltype(com)> pq(com);

        for(auto it = visited.begin(); it != visited.end(); ++it){
            for(int i = 0; i < map.size(); ++i)
                if( !visited.count(i) && map[*it][i] != INT_MAX)
                    pq.push(Edge(*it, i, map[*it][i]));
        }
        
        res.push_back(pq.top());
        visited.insert(pq.top().dst);
    }
    return res;
}

int main(){  
    int n = 7, e = 11;  
    vector<vector<int>> map(n, vector<int>(n, INT_MAX));
    vector<vector<int>> paths{{0, 1, 7},
                              {0, 3, 5},
                              {1, 2, 8},
                              {1, 3, 9},
                              {1, 4, 7},
                              {2, 4, 5},
                              {3, 4, 15},
                              {3, 5, 6},
                              {4, 5, 8},
                              {4, 6, 9},
                              {5, 6, 11}};



    for (auto p : paths){  
        map[p[0]][p[1]] = p[2];
        map[p[1]][p[0]] = p[2];
    }  

    auto res = Prim(map, paths);
    
    int total_len = 0;
    for(auto e : res){
        cout << e.src << "---" << e.dst << " Len: " << e.weight << endl;
        total_len += e.weight;
    }
    cout << "Tree Length: " << total_len << endl;
    return 0;  
}  
