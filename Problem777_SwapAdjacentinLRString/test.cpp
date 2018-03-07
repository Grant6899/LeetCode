/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 21:39:56 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        vector<pair<char, int>> stLR, edLR;

        for(int i = 0; i < start.size(); ++i)
            if(start[i] == 'L' || start[i] == 'R')
                stLR.push_back(make_pair(start[i], i));

        for(int i = 0; i < end.size(); ++i)
            if(end[i] == 'L' || end[i] == 'R')
                edLR.push_back(make_pair(end[i], i));

        if(stLR.size() != edLR.size())
            return false;

        for(int i = 0; i < stLR.size(); ++i)
            if(stLR[i].first == edLR[i].first){
                if(stLR[i].first == 'L' && stLR[i].second < edLR[i].second)
                    return false;
                if(stLR[i].first == 'R' && stLR[i].second > edLR[i].second)
                    return false;
            }
            else
                return false;


        return true;

    }
};

int main(){
    Solution s;
    cout << s.canTransform("RXXLRXRXL", "XRLXXRRLX") << endl;
    return 0;
}
