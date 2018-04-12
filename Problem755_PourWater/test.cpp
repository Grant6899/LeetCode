/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Apr 11 21:00:21 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for(int i = 0; i < V; ++i)
			addDrop(heights, K, 0);

		return heights;
    }

	bool addDrop(vector<int>& heights, int k, int move){
        //cout << "addDrop: " << k << " " << move << endl;

		if(move <= 0 && k - 1 >= 0 && heights[k] >= heights[k-1] && addDrop(heights, k-1, -1))
			return true;

		if(move >= 0 && k + 1 < heights.size() && heights[k] >= heights[k+1] && addDrop(heights, k+1, +1))
			return true;

        if(move != 0 && heights[k] == heights[k - move]) return false;

		heights[k]++;

		return true;
	}
};

int main(){
    Solution s;
    vector<int> heights{2,1,1,2,1,2,2};
    auto ans = s. pourWater(heights, 4, 3);
    return 0;
}
