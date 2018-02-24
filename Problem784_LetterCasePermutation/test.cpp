/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Feb 23 21:49:10 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> prev{""};

        for(char ch : S){
            vector<string> cur;
            if(isdigit(ch)){
                for(string str : prev){
                    str += ch;
                    cur.push_back(str);
                }
            }
            else{
                if('a' <= ch && ch <= 'z'){
                    for(string str : prev){
                        cur.push_back(str + ch);
                        cur.push_back(str + char(toupper(ch)));
                    }
                }
                else{
                    for(string str : prev){
                        cur.push_back(str + ch);
                        cur.push_back(str + char(tolower(ch)));
                    }
                }
            }
            prev = cur;
        }

        return prev;
    }
};

int main(){
    Solution s;

    auto ans = s.letterCasePermutation("a1b2");
    for(string str : ans)
        cout << str << " ";
    return 0;
}
