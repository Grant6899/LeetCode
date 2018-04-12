/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Apr 11 21:26:11 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {

        vector<pair<int, int>> edges;

        for(auto building : buildings){
            edges.push_back({building[0], -building[2]});
            edges.push_back({building[1], building[2]});
        }

        sort(edges.begin(), edges.end());

        multiset<int> h_pool{0};

        vector<pair<int, int>> res;


        int pre = 0, cur = 0;
        for(auto edge : edges){

            if(edge.second < 0)
                h_pool.insert(-edge.second);
            else
                // erase one element, don't use h_pool.erase(edge.second) cause it will delete all elements
                h_pool.erase(h_pool.find(edge.second));

            cur = *(h_pool.rbegin());

            if(cur != pre){
                res.push_back({edge.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> buildings{{0, 2, 5}, {2, 5, 3}};
    auto ans = s. getSkyline(buildings);
    return 0;
}
