/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:15:24 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for(int i = 0; i < fronts.size(); ++i)
            if(fronts[i] == backs[i])
                same.insert(fronts[i]);

        int res = 3000;
        for(int i : fronts)
            if(res > i && same.count(i) == 0)
                res = i;

        for(int i : backs)
            if(res > i && same.count(i) == 0)
                res = i;

        return res == 3000? 0 : res;
    }
};

int main(){
    Solution s;
    vector<int> fronts{1,2,4,4,7}, backs{1,3,4,1,3};
    cout << s.flipgame(fronts, backs) << endl;
    return 0;
}
