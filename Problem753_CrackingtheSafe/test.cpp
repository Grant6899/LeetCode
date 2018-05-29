/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:30:59 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int n, k, v;
    vector<vector<bool> > visited;
    string sequence;
public:
    string crackSafe(int n, int k) {
        if (k == 1) return string(n, '0');
        this->n = n;
        this->k = k;
        v = 1;

		for (int i = 0; i < n -1; ++i)
			v *= k;

        visited.resize(v, vector<bool>(k, false));

		dfs(0);

        return sequence + sequence.substr(0, n - 1);
    }

    void dfs(int u) {
        for (int i = 0; i < k; ++i) {
            if (!visited[u][i]) {
                visited[u][i] = true;
                //cout << u << " " << i << endl;
                dfs((u * k + i) % v);
                sequence.push_back('0' + i);
                //cout << sequence << endl;
            }
        }
    }
};

int main(){
    Solution s;
    cout << s.crackSafe(2, 2) << endl;
    return 0;
}
