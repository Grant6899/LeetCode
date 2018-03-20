/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Mar 17 20:23:48 2018
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
		
		sort(points.begin(), points.end(), [](pair<int, int>& a, pair<int, int>& b){return a.second < b.second;});
		
        /*for(auto x : points){
            cout << x.first << " " << x.second << endl;
        }*/
		
		long long res = 0, cur_arrow = - 1e11;
        for(auto p : points){
			if(cur_arrow < p.first){
				res++;
				cur_arrow = p.second;
			}
		}
		
		return res;
    }
};

int main(){
    Solution s;
    vector<pair<int,int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << s. findMinArrowShots(points) << endl;
    return 0;
}
