/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 24 15:19:41 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<int> current;
        find(0, 0, result, current, s);
        return result;
    }

    void find(int next, int cur_loc, vector<string>& result, vector<int>& current, const string& s) {
        if (next == 4 && cur_loc == s.size()) {
            result.push_back(currenttostr(current));
            return;
        }


        if (s[cur_loc] == '0') {
            current.push_back(0);
            find(next + 1, cur_loc + 1, result, current, s);
            current.pop_back();
        }
        else {
            for (int i = 1; i <= 3 && cur_loc + i <= s.size(); ++i) {
                int temp = stoi(s.substr(cur_loc, i));
                if (((s.size() - cur_loc - i) >= (3 - next))
                    && ((s.size() - cur_loc - i) <= (3 - next) * 3)
                    && temp <= 255
                    ) {
                    current.push_back(stoi(s.substr(cur_loc, i)));
                    find(next + 1, cur_loc + i, result, current, s);
                    current.pop_back();
                }
            }
        }
        
    }

    string currenttostr(const vector<int>& cur) {
        string s = to_string(cur[0]);
        for (int i = 1; i <= 3; ++i)
            s += "." + to_string(cur[i]);
        return s;
    }

};

int main(){
    Solution s;
    auto ans = s.restoreIpAddresses("25525511135");
    for(auto it = ans.begin(); it < ans.end(); ++it)
        cout << *it << "|";
    cout << endl;
    return 0;
}

