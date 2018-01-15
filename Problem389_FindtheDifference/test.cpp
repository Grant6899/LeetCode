/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 15:25:28 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        string str = s + t;

        char ch = str[0];
        for(int i = 1; i < str.size(); ++i){
            ch ^= str[i];
        }
        return ch;
    }
};

int main(){
    Solution s;
    cout << s.findTheDifference("abcd", "cdfab") << endl;
    return 0;
}
