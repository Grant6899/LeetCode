/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 31 15:49:19 2017
 ************************************************************************/

#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        map<char, char> map1, map2;
        
        for(int i = 0; i < s.size(); ++i){
            if(map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end()){
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else if(map1[s[i]] != t[i])
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isIsomorphic("paper", "title") << endl;
    return 0;

}
