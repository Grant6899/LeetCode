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
    bool isMatch(string s, string p) {
        int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

        for(i=0,j=0 ; i<slen; ++i, ++j)
        {
            if(p[j]=='*')
            { //meet a new '*', update traceback i/j info
                iStar = i;
                jStar = j;
                --i;
            }
            else
            {
                if(p[j]!=s[i] && p[j]!='?')
                {  // mismatch happens
                    if(iStar >=0)
                    { // met a '*' before, then do traceback
                        i = iStar++;
                        j = jStar;
                    }
                    else return false; // otherwise fail
                }
            }
        }
        while(p[j]=='*') ++j;
        return j==plen;
    }
};

int main(){
    Solution s;

    cout << s.isMatch("admbccd", "a*ba*c?d") << endl;
    return 0;
}
