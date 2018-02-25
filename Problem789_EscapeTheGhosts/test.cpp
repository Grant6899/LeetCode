/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Feb 25 08:33:35 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int benchmark = abs(target[0]) + abs(target[1]);
        
        for (auto g : ghosts)
            if(abs(target[0] - g[0]) + abs(target[1] - g[1]) <= benchmark)
                return false;
        
        return true;
    }
};

int main(){
    vector<vector<int>> ghosts{{1,2}, {2, 0}};
    vector<int> target{0,1};
    Solution s;

    cout << s.escapeGhosts(ghosts, target) << endl;
    return 0;
}
