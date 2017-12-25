/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 25 11:02:28 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            
            while(!chValid(s[left]))
                left++;
            while(!chValid(s[right]))
                right--;

            if(left < right && !chEqual(s[left], s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }

private:
    bool chValid(char ch){
        return chAlpha(ch) || chNumeric(ch);
    }

    bool chAlpha(char ch){
        return ('A' <= ch && ch <='Z') || ('a' <= ch && ch <='z');
    }

    bool chNumeric(char ch){
        return ('0' <= ch && ch <= '9');
    }

    bool chEqual(char ch1, char ch2){
    if(chAlpha(ch1) && chAlpha(ch2))
        return (ch1 == ch2 || abs(ch1 - ch2) == 32);
    if(chNumeric(ch1) && chNumeric(ch2))
        return ch1 == ch2;
    return false;
    }
};

int main(){
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;

    return 0;
}
