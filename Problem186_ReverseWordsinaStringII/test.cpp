/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 13 18:35:09 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& str) {
		reverse(str.begin(), str.end());
		for (int i = 0, j = 0; i < str.size(); i = j + 1) {
			for (j = i; j < str.size() && str[j] != ' '; ++j);
				reverse(str.begin()+i, str.begin()+j);
		}
	}
};

int main(){
    Solution s;
    vector<char> words{'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    s. reverseWords(words);
    return 0;
}

