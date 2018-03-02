/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 29 20:58:12 2018
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p){
        int s_last_match_begin = -1;
        int p_last_asterisk_pos = -1;

        int s_ptr = 0, p_ptr = 0;
        while(s_ptr < s.size()){
            if(p[p_ptr] == '*'){
                
                while(p_ptr+1 < p.size() && p[p_ptr+1] == '*')
                    p_ptr++;

                s_last_match_begin = s_ptr;
                p_last_asterisk_pos = p_ptr++;
            
            }
            else {

                if(s[s_ptr] == p[p_ptr] || p[p_ptr] == '?'){
                    s_ptr++;
                    p_ptr++;
                }
                else{ 
                    if(p_last_asterisk_pos != -1){
                        s_ptr = ++s_last_match_begin;
                        p_ptr == p_last_asterisk_pos + 1;
                    }
                    else
                        return false;
                }
            }
        }
        while(p[p_str] == '*') p_ptr++;
        return(p.empty());
    }

    bool isMatch(const char *s, const char *p) {
        // the char in s which the char right after '*' compares against before backtrack
        const char *s_last_match_begin = NULL;
        const char *p_last_asterisk_pos = NULL;
 
        while (*s) {
            if ('*' == *p) {
                // skip continous '*' till reaching the last one
                while ('*' == *(p + 1))   p++;
 
                s_last_match_begin = s;
                // p++, but not s++, to start w/ matching empty string
                p_last_asterisk_pos = p++;
            } else {
                if (*s == *p || '?' == *p) {
                    s++;
                    p++;
                } else {
                    if (p_last_asterisk_pos != NULL) {
                        // backtrack: '*' matches one more char
                        s = ++s_last_match_begin;
                        p = p_last_asterisk_pos + 1;
                    } else {
                        return false;
                    }
                }
            }
        }
 
        // if string is over, the rest of pattern has to be all '*' to match
        while ('*' == *p)  p++;
        return (!*p);
    }
};

int main(){
    Solution s;

    cout << s.isMatch("aa", "*") << endl;
    return 0;
}
