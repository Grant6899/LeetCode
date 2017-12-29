/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Dec 29 18:12:13 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();

        for(int i = 1; i <= s.size() / 2;++i){
            bool temp = true;
            if(len % i == 0){
                int st = 0;
                while(st + 2*i <= s.size()){
                    if(s.substr(st, i) != s.substr(st+i, i)){
                        temp = false;
                        break;
                    } 
                    st += i;
                }
                
                if(temp)
                    return true;
            }
        }

        return false;
    }
};

int main(){
    Solution s;
    cout << s.repeatedSubstringPattern("abac") << endl;
    return 0;
}
