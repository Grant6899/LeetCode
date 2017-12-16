/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 16 16:47:30 2017
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0, horizontal = 0; 
        for(auto it = moves.begin(); it < moves.end(); ++it){
            if (*it == 'U')
                ++vertical;
            if (*it == 'D')
                --vertical;
            if (*it == 'R')
                ++horizontal;
            if (*it == 'L')
                --horizontal;
        }

        if (vertical == 0 && horizontal == 0)
            return true;
        else
            return false;
    }
};

int main(){
    Solution s;
    cout << s.judgeCircle("UD") << endl;
    return 0;
}
