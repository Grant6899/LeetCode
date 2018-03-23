/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 22 19:32:00 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<int> out(101, 0);
		vector<vector<vector<double>>> mem(100, vector<vector<double>>(25, vector<double>(25)));

		return dfs(r, c, N, K, mem);
    }

	double dfs(int i, int j, int N, int K, vector<vector<vector<double>>>& mem){
		double inside = 0;
		if(K == 0) return 1;

		for(int k = 0; k < 8; ++k)
			if(!outRange(i + delta[k][0], j + delta[k][1], N)){
				inside += 0.125 * (mem[K-1][i + delta[k][0]][j + delta[k][1]]? mem[K-1][i + delta[k][0]][j + delta[k][1]] : dfs(i + delta[k][0], j + delta[k][1], N, K-1, mem));
			}
		mem[K][i][j] = inside;
		return inside;
	}

private:
	vector<vector<int>> delta{{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};

	bool outRange(int i, int j, int N){
		return(i < 0 || i >= N || j < 0 || j >= N);
	}
};

int main(){
    Solution s;
    cout << s. knightProbability(3, 2, 1,1) << endl;
    return 0;
}
