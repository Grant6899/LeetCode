/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 14:41:21 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b? -1 : max(a.size(), b.size());
    }
};

int main(){
    Solution s;
    cout << s.findLUSlength("abc", "cde") << endl;
    return 0;
}
