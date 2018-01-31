/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan 30 22:34:02 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 1)
            return 0;
        
        int prev = cost[0], cur = cost[1];
        

        for(int i = 2; i < cost.size(); ++i){
            int temp = cur;
            cur = cost[i] + min(prev, cur);
            prev = temp;
            cout << i << " : " << cur << endl;
        }

        return cur;
    }
};

int main(){
    Solution s;
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << s.minCostClimbingStairs(cost) << endl;
    return 0;
}
