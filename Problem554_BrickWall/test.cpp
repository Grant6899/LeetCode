/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 18:57:32 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
		unordered_map<int, int> count;
		int res = 0, maxx = INT_MIN;
		for(int i = 0; i < wall.size(); ++i){
			int cur = 0;
			for(int j = 0; j < wall[i].size() - 1;++j){
				cur += wall[i][j];
                //cout << cur << " ";
				count[cur]++;
				maxx = max(count[cur], maxx);
			}
//            cout << endl;
		}
		return maxx != INT_MIN ? wall.size() - maxx : wall.size();
    }
};


int main(){
    Solution s;
    vector<vector<int>> wall{{1,2,2}, {2,1,2}};

    cout << s.leastBricks(wall) << endl;
    return 0;
}
