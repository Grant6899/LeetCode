/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 21 17:37:47 2018
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums, signs;
        
        //signs.push(1);

        int res = 0;
        int num = 0;
        int sign = 1;

        for(char ch : s){    
            if(isdigit(ch))
                num = num * 10 + ch - '0';
            else{
                res += sign * num;
                num = 0;
                if(ch == '+')
                    sign = 1;
            
                if(ch == '-')
                    sign = -1;
            
                if(ch == '('){
                    nums.push(res);
                    signs.push(sign);
                    res = 0;
                    sign = 1;
                }
            
                if(ch == ')'){
                    res = nums.top() + signs.top() * res;
                    nums.pop();
                    signs.pop();
                }
            }
        
        }
        res += sign * num;
        return res;
    }
};


int main(){
    Solution s;
    string exp = "(1+(4+5+2)-3)+(6+8)";
    
    cout << s.calculate(exp) << endl;

    return 0;
}
