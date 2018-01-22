/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 21 18:39:33 2018
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0, cur = 0, num = 0;
        char last_pm = '+', last_md = '*';

        for(char ch : s){

            if(isdigit(ch))
                num = num * 10 + ch;
            
            if(ch == '+'){
                last_pm = '+';
                last = :ch;
            }
            
            if(ch == '-'){
                last_pm = '-';
                last = ch;
            }
            
            if(ch == '*'){
                last_md = '*';
                last = ch;
            }
            
            if(ch == '/'){
                last_md = '/';
                last = ch;
            }

            if()
            


        }
        


    }
};

int main(){
    Solution s;

    cout << s.calculate("3+2*5*2+5*6") << endl;

    return 0;
}
