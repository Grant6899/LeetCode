/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 15 21:41:30 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        
        if(s1.size() != s2.size())
            return false;
        
        unordered_map<char, int> cnt;
        
        for(int i = 0; i < s1.size(); ++i){
            cnt[s1[i]]++;
            cnt[s2[i]]--;
            if(cnt[s2[i]] == 0) cnt.erase(s2[i]);
        }
        
        for(auto a : cnt)
            if(a.second != 0)
                return false;

        for(int i = 1; i <= s1.size() - 1; i++){
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(s1.size()-i)) && isScramble(s1.substr(i), s2.substr(0,s1.size()-i)))
                return true;
        }
        return false; 
    }
};

int main(){
    Solution s;
    cout << s.isScramble("abcd", "dcba") << endl;
    return 0;
}
