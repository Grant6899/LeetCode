/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Feb 23 22:07:17 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> map(n, vector<int>(n, INT_MAX));
        // ans[i][j] is the lowest cost from src to i with less than j stops
        vector<vector<int>> ans(n, vector<int>(K + 1, INT_MAX));

        for(auto flight : flights){
            map[flight[0]][flight[1]] = flight[2];
            if(flight[0] == src)
                ans[flight[1]][0] = map[flight[0]][flight[1]];
        }

        for(int i = 1; i <= K; ++i){
            
            for(int j = 0; j < n; ++j)
                ans[j][i] = ans[j][i-1];
            
            for(const vector<int>& f: flights){
                ans[f[1]][i] = min(ans[f[1]][i], ans[f[0]][i-1] + f[2] > 0? ans[f[0]][i-1] + f[2] : INT_MAX);
            }
        }

        return ans[dst][K] == INT_MAX? -1 : ans[dst][K];
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges{{0, 1, 2}, {1, 2, 1}, {2, 0, 10}};
    cout << s.findCheapestPrice(3, edges, 1, 2, 1) << endl;

    return 0;
}
