/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 20 16:23:14 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for(auto ch : s)
            counts[ch]++;

        bool odd_find = false;
        int res = 0;
        for(auto ele : counts){
            if(!odd_find && (ele.second & 1))
                odd_find = true;
            res += ele.second & 0xFFFFFFFE;
        }

        if(odd_find)
            res++;
        return res;
    }
};

int main(){
    Solution s;

    cout << s.longestPalindrome("abbccddddd") << endl;
    return 0;
}
