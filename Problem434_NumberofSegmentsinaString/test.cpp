/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 17 19:21:04 2017
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int result = 0; 
        for(auto it = s.begin(); it < s.end(); ++it){
            if(*it == ' '){
                while(*it == ' ')
                    ++it;
            }
            else{
                ++result;
                while(*it != ' ')
                    ++it;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    cout << s.countSegments("Hello, My name is Grant.") << endl;
    return 0;
}
