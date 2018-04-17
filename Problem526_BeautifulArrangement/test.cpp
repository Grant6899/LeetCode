/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr 16 18:51:43 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<bool> visited(N + 1, false);
	
		int res = 0;
		dfs(1, N, visited, res);
        
		return res;
    }
	
	void dfs(int i, int N, vector<bool>& visited, int& res){
		if(i == N + 1){
			res++;
			return;
		}
	
		for(int candidate = 1; candidate <= N; ++candidate){
			if(!visited[candidate] && (candidate >= i && candidate % i == 0 || i >= candidate && i % candidate == 0)){
                visited[candidate] = true;
				dfs(i + 1, N, visited, res);
				visited[candidate] = false;
			}
		}
	}
};

int main(){
    Solution s;
    cout << s.countArrangement(2) << endl;
    return 0;
}
