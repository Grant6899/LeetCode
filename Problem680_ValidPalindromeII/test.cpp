/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 21:05:54 2018
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if(isPalindrome(s, 0, s.size() - 1))
            return true;

        for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
            if(s[i] != s[j])
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
    }

    bool isPalindrome(string s, int l, int r){
        for(int i = l, j = r; i < j; ++i, --j)
            if(s[i] != s[j])
                return false;
        return true;
    }

};

int main(){
    Solution s;
    cout << s.validPalindrome("abc") << endl;
    return 0;
}
