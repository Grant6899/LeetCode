/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 14 13:42:15 2018
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int res = 0;

        vector<vector<int>> map(N, vector<int>(N, INT_MAX));

        for(int i = 0; i < times.size(); i++)
            map[times[i][0]-1][times[i][1]-1] = times[i][2];

        for(int i = 0; i < N; i++) 
            map[i][i] = 0;

        auto dist = dijkstra(map, N, K-1);

        for(int i = 0; i < dist.size(); ++i)
            res = max(res, dist[i]);

        return res== INT_MAX? -1 : res;
    }

    vector<int> dijkstra(vector<vector<int>>& map, int N, int src){
        // dist[i] to store distance between src and i
        vector<int> dist(N, INT_MAX), prev(N, 0);
        vector<bool> S(N, false);

        for(int i = 0; i < N; i++){
            dist[i] = map[src][i];
            if(dist[i] == INT_MAX)
                prev[i] = -1;
            else
                prev[i] = src;
        }
        
        for(int i = 0; i < N; i++){
            int mindist = INT_MAX;
            int u = src;
            
            for(int j = 0; j < N; ++j)
                if((!S[j]) && dist[j] < mindist){
                    u = j;
                    mindist = dist[j];
                }

            S[u] = true;

            for(int j = 0; j < N; ++j){
                if((!S[j]) && map[u][j] < INT_MAX){
                    if(dist[u] + map[u][j] < dist[j]){
                        dist[j] = dist[u] + map[u][j];
                        prev[j] = u;
                    }
                }
            }
        }
        
        return dist;
    }
};



int main(){
    vector<vector<int>> map {{1,2,1},{2,3,7},{1,3,4},{2,1,2}};

    Solution s;

    cout << s.networkDelayTime(map, 3, 1) << endl;

    return 0;
}
