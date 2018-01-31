/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 29 23:01:09 2018
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!*p)
            return !*s;
        if (p[1] == '*')
            return isMatch(s, p+2) || (*p == '.' && *s || *s == *p) && isMatch(s+1, p);
        if (*p == '.')
            return *s && isMatch(s+1, p+1);
        return *s == *p && isMatch(s+1, p+1);
    }
};

int main(){
    char ss[10] = "aa";
    char p[10] = "*";

    Solution s;
    cout << s.isMatch(ss, p) << endl;
    return 0;
}
