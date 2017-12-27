/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec 27 13:12:11 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;
        int result = 0;
        for(auto it = nums.begin(); it < nums.end();++it)
            map[*it]++;

        for(auto it : map ){
            if(map.find(it.first + 1) != map.end() && it.second + map[it.first+1] > result)
                result = it.second + map[it.first + 1];
        }
        return result;
    }
};

int main(){
    vector<int> vec {1,3,2,2,5,2,3,7};
    Solution s;
    cout << s.findLHS(vec) << endl;
    return 0;
}
