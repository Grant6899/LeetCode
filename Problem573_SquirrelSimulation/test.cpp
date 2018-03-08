/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  8 18:37:26 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {

		int treetonutssum = 0;
		for(auto nut : nuts)
			treetonutssum += distance(nut, tree);

		int mindis = INT_MAX;
		for(auto nut : nuts)
			mindis = min( mindis, distance(nut, squirrel) + treetonutssum - distance(nut, tree));

		return mindis + treetonutssum;
    }


	int distance(vector<int>& a, vector<int>& b){
		return abs(a[0] - b[0]) + abs(a[1] - b[1]);
	}


};

int main(){
    vector<int> tree{2, 2}, squirrel{4,4};
    vector<vector<int>> nuts{{3,0},{2,5}};

    Solution s;
    cout << s.minDistance(5, 7, tree, squirrel, nuts) << endl;
    return 0;
}
