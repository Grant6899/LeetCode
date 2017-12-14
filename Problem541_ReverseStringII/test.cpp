/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec 13 22:18:26 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, len = s.size();
        bool flag = true;
        while(i + k <= len){
            if (flag){
                for( int j = 0; j < k/2; ++j )        
                    std::swap(s[i + j], s[i + k - j - 1]);
                flag = false;
            }
            else
                flag = true;
            i+=k;
        }
        
        if (flag)
            for( int j = 0; j < (len - i)/2; ++j )        
                std::swap(s[i + j], s[len - j - 1]);
    return s;
    }
};

int main(){
    Solution s;
    cout << s.reverseStr("abcdefghijk", 4) << endl;
    return 0;

}
