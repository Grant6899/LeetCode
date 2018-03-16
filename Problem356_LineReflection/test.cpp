/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 15 21:37:40 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int len = points.size();
        if (len==0 || len==1) return true;
    
        unordered_map<int, set<int>> mp;
        int max = points[0].first, min = points[0].first;
        // build the map, find min and max
        for (int i=0; i<len; ++i) {
            if (points[i].first < min) min = points[i].first;
            if (points[i].first > max) max = points[i].first;
            mp[points[i].second].insert(points[i].first);
        }
        double line = (min + max) / 2.0;
    
        // mirror the sorted x value in the set using two pointer
        for (auto it = mp.begin(); it!=mp.end(); ++it) {
            set<int>& s = it->second;
            for (auto start=s.begin(), end = s.end(); start!=end; ++start) {
                if ((*start + *(--end)) / 2.0 != line)
                    return false;
                if (start==end) break;
            }
        }
        return true;
    }
};

int main(){
    vector<pair<int, int>> p{{1,2}, {2,1}};
    Solution s;
    cout << s.isReflected(p) << endl;
    return 0;
}
