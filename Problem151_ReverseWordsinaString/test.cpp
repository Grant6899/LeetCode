/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Dec 26 20:08:50 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
    }*/

    void reverseWords(string &s) {
        while(s.back() == ' ')
            s.pop_back();
        
        reverse(s.begin(), s.end());
        
        while(s.back() == ' ')
            s.pop_back();
        
        for(auto it = s.begin(); it != s.end(); ++it){
            if(*it == ' '){
                it = s.erase(it);
                continue;
            } 
            auto left = it;
            while(it != s.end() && *it != ' ') ++it;
            reverse(left, it);
            
            if(it == s.end())
                break;
        }
    }

};

int main(){
    Solution s;
    string str = "   a   b ";
    s.reverseWords(str);
    cout << "'" << str << "'" << endl;
    return 0;
}
