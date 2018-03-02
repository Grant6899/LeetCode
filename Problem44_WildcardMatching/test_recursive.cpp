/*************************************************************************
	> File Name: test_recursive.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Feb 27 19:22:05 2018
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        if(p.size() > 1 && p[0] == '*' && p[1] == '*')
            return isMatch(s, p.substr(1));
        
        if(p.empty())
            return s.empty();
        
        if(p[0] == '*')
            return isMatch(s, p.substr(1)) || !s.empty() && isMatch(s.substr(1), p);
        
        if(p[0] == '?')
            return !s.empty() && isMatch(s.substr(1), p.substr(1));
        
        return p[0] == s[0] && isMatch(s.substr(1), p.substr(1));
        
    }
};

int main(){
    Solution s;

    cout << s.isMatch("aa", "*") << endl;
    return 0;
}
