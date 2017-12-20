/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 18 19:56:03 2017
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int up, down;
        up = down = 0;
        for(auto it = s.begin(); it < s.end(); ++it){
            if(*it == '('){
                ++up;
                ++down;
            }
            else if (*it == ')'){
                --up;
                --down;
            }
            else if (*it == '*'){
                ++up;
                --down;
            }
            down = max(down, 0);
            if(up < 0) return false;
        }
        return (down == 0);
    }
};

int main(){
    Solution s;
    cout << s.checkValidString("(*))") << endl;
    return 0;
}
