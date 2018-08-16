/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu May 31 18:38:24 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct T {
    int t, x, y;
    T(int a, int b, int c) : t (a), x (b), y (c){}
};

class Solution {
public:


    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size (), res = 0;
        auto com = [](const T& t1, const T& t2){ return t1.t > t2.t;};

        priority_queue<T, vector<T>, decltype(com)> pq(com);

        pq.push(T(grid[0][0], 0, 0));
        vector<vector<int>> visited(N, vector<int>(N, 0));
        visited[0][0] = 1;
        static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

        while (true) {
            auto p = pq.top ();
            pq.pop ();
            res = max(res, p.t);
            if (p.x == N - 1 && p.y == N - 1) return res;
            for (auto& d : dir) {
                int i = p.x + d[0], j = p.y + d[1];
                if (i >= 0 && i < N && j >= 0 && j < N && !visited[i][j]) {
                    visited[i][j] = 1;
                    pq.push (T(grid[i][j], i, j));
                }
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid{{0, 1}, {3, 2}};
    cout << s.swimInWater(grid) << endl;
    return 0;
}
