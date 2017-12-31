/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 31 12:37:51 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total(0), subsum(INT_MAX), start(0);
        for(int i = 0; i < n; ++i){
            total += gas[i] - cost[i];
            if(total < subsum) {
                subsum = total;
                start = i + 1;
            }
        }
        return (total < 0) ?  -1 : (start%n);
    }
};

int main(){
    vector<int> gas = { 4, 5, 1,3};
    vector<int> cost = {1,4,2,3};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
