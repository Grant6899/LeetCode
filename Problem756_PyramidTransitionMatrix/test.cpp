/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 20 16:38:02 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> rules;

        for (string rule : allowed) {
            if (rules.find(rule.substr(0, 2)) == rules.end()) {
                vector<char> tmp = { rule[2] };
                rules[rule.substr(0, 2)] = tmp;
            }
            else
                rules[rule.substr(0, 2)].push_back(rule[2]);
        }
        int tar = bottom.size();
        vector<string> pyramid{ bottom };
        bool find = findNext(pyramid, 0, rules, tar);
        return find;
    }

    bool findNext(vector<string>& pyramid, int index, unordered_map<string, vector<char>>& rules, int tar) {
        if (pyramid.size() == tar && pyramid.back().size() == 1) {
            return true;
        }

        if (pyramid.size() == 1 || pyramid.back().size() + 1 == pyramid[pyramid.size()-2].size()) {
            pyramid.push_back("");
            if (findNext(pyramid, 0, rules, tar))
                return true;
            pyramid.pop_back();
        }
        else {
            string bottom = pyramid[pyramid.size() - 2];
            if (rules.find(bottom.substr(index, 2)) != rules.end()) {
                for (char ch : rules[bottom.substr(index, 2)]) {
                    pyramid.back().push_back(ch);
                    if (findNext(pyramid, index + 1, rules, tar)) {
                        return true;
                    }
                    pyramid.back().pop_back();
                }
            }
        }
        return false;
    }
};

int main(){

    Solution s;

    vector<string> allowed {"ABD","BCE","DEF","FFF"};

    cout << s.pyramidTransition("ABC", allowed) << endl;
    return 0;
}

