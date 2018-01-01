/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 31 15:49:19 2017
 ************************************************************************/

#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> map1, map2;
        string ptn1 = "", ptn2 = "";
        int c1 = 0, c2 = 0;
        
        for_each(s.begin(), s.end(), [](char& ch){
            if(ch >= 'a' && ch <= 'z')
                ch = toupper(ch);});
        
        for_each(t.begin(), t.end(), [](char& ch){
            if(ch >= 'a' && ch <= 'z')
                ch = toupper(ch);});

        for(int i = 0; i < s.size(); ++i){
            
            if(map1.find(s[i]) == map1.end()){ 
                ptn1 += to_string(c1);
                map1[s[i]] = c1++;
            }
            else
                ptn1 += to_string(map1[s[i]]);
                
            if(map2.find(t[i]) == map2.end()){ 
                ptn2 += to_string(c2);
                map2[t[i]] = c2++;
            }
            else
                ptn2 += to_string(map2[t[i]]);
                
            if(ptn1 != ptn2)
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
