/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  8 18:29:43 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> x, y;

		for(int i = 0; i < grid.size(); ++i)
        for(int j = 0; j < grid[0].size(); ++j)
            if(grid[i][j] == 1){
			    x.push_back(i);
			    y.push_back(j);
		    }

		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		int res = 0;
        /*
        for(int a : x)
            cout << a << " ";
        cout << endl;
        for(int a : y)
            cout << a << " ";
*/
		for(int i = 0; i < x.size() / 2; ++i)
			res += x[x.size() - 1 - i] - x[i] + y[x.size() - 1 - i] - y[i];
		return res;
    }
};

int main(){
    vector<vector<int>> grid{{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    Solution s;
    cout << s.minTotalDistance(grid) << endl;
    return 0;
}
