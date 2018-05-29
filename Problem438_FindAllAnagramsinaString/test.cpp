/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:52:53 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pw(256,0), sw(256,0), res;
        if(s.size() < p.size())
           return res;

        for(int i = 0; i < p.size(); ++i){
            pw[p[i]]++;
            sw[s[i]]++;
        }
        if(pw == sw)
           res.push_back(0);

        for(int i = p.size(); i < s.size(); ++i){
            sw[s[i]]++;
            sw[s[i-p.size()]]--;
            if(pw == sw)
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    auto ans = s.findAnagrams("abab", "ab");
    return 0;
}
