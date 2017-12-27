/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec 27 13:30:23 2017
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
#include<utility>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> dic;

        for (auto it = s.begin(); it < s.end(); it++)
            dic[*it]++;

        vector<pair<char, int>> vec;

        auto it = dic.begin();
        while (it != dic.end()){
            vec.push_back(make_pair(it->first, it->second));
            ++it;
        }
        
        sort(vec.begin(), 
             vec.end(), 
             [](const pair<char, int>& a, const pair<char, int>& b) { return a.second > b.second; }
        );
        
        string result = "";

        for (auto it : vec)
            result += string(it.second, it.first);

        return result;
    }
};

int main(){
    Solution s;
    cout << s.frequencySort("tree") << endl;
    return 0;
}
