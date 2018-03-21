/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 20 22:13:05 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> idx(1001);

		for(int i = 1; i <= 1000; ++i)
			idx[i] = i;

		for(auto e : edges){
            //cout << "adding (" << e[0] << ", " << e[1] << ")   ";
			if(idx[e[0]] == idx[e[1]])
				return {e[0], e[1]};
			else{
                int temp_idx = idx[e[1]];
				for(int i = 1; i <= 1000; ++i){
					if(idx[i] == temp_idx)
						idx[i] = idx[e[0]];
                }

			}
           // for(int i = 1; i <= 10; ++i)
                //cout << idx[i] << ' ';
           // cout << endl;
		}
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges{{1, 2}, {2, 3}, {1, 3}};
    auto ans = s. findRedundantConnection(edges);
    for(int a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}
