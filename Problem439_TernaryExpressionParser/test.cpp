/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:41:31 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
        if(expression.find(":") == string::npos){
            return expression;
        }

        if(expression[0] == 'T'){
            int counter = 0, i = 2;
            for(; i < expression.size(); ++i){
                if(expression[i] == ':')
                    counter++;
                if(expression[i] == '?')
                    counter--;
                if(counter == 1)
                    break;
            }
            return parseTernary(expression.substr(2, i - 2));
        }
        else{
            int counter = 0, i = 2;
            for(; i < expression.size(); ++i){
                if(expression[i] == ':')
                    counter++;
                if(expression[i] == '?')
                    counter--;
                if(counter == 1)
                    break;
            }
            return parseTernary(expression.substr(i + 1));
        }
    }
};

int main(){
    Solution s;
    cout << s.parseTernary("T?2:3") << endl;
    return 0;
}
