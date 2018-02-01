/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  1 18:29:32 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int prev = 0, cur = 0;

		for(int i = 0; i < t.size(); ++i){
			if(s[prev] == t[i])
				cur = prev + 1;
			else
				cur = prev;
            //cout << cur << ' ';
			prev = cur;
		}

		return cur == s.size();
    }
};


int main(){
    Solution s;
    cout << s.isSubsequence("ace", "abcde") << endl;
    return 0;
}
