/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:09:21 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        
        int left = 0, right = 0;
        
        while(left < S.size()){
            while(right < S.size() && S[right] == S[left])
                ++right;
            if(right - left >= 3)
                res.push_back({left, right - 1});
            left = right;
        }
        
        return res;
    }
};

int main(){
    Solution s;
    auto ans = s. largeGroupPositions("abcdddeeeeaabbbcd");
    return 0;
}
