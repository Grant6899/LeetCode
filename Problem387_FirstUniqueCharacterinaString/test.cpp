/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan  9 20:44:44 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dic;
        int len = s.size();

        for(int i = 0; i < len; ++i){
            dic[s[i]]++;
        }

        for(int i = 0; i < len; ++i){
            if(dic[s[i]] == 1)
                return i;
        }

        return -1;
    }
};

int main(){
    Solution s;

    cout << s.firstUniqChar("leetcode") << endl;
    return 0;
}
