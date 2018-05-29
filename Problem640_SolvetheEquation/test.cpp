/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:44:47 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int xval = 0, val = 0, left = 1, sign = 1;
        char buff;
        stringstream ss(equation);
        while(ss.peek() > 0)
        {
            int num = 0;
            if(isdigit(ss.peek()))
            {
                ss >> num;
                if(num == 0 && ss.peek() == 'x')
                {
                    ss >> buff;
                }
            }
            else if(ss.peek() == '+')
            {
                ss >> buff;
                sign = 1;
            }
            else if(ss.peek() == '-')
            {
                ss >> buff;
                sign = -1;
            }
            else if(ss.peek() == '=')
            {
                ss >> buff;
                left = -1;
                sign = 1;
            }

            if(ss.peek() == 'x')
            {
                xval += left*sign*max(num,1);
                ss >> buff;
            }
            else
            {
                val += left*sign*num;
            }
        }
        if(xval != 0)
        {
            return string("x=") + to_string(-val/xval);
        }
        if(xval == 0 && val == 0)
            return "Infinite solutions";
        return "No solution";

    }
};

int main(){
    Solution s;
    cout << s.solveEquation("x+5-3+x=6+x-2") << endl;
    return 0;
}
