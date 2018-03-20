/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 19 22:21:55 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    string similarRGB(string color) {
        
        string res = "#";
        
        res += getsimilar(color.substr(1, 2));
        res += getsimilar(color.substr(3, 2));
        res += getsimilar(color.substr(5, 2));
        //cout << getsimilar("f9") << endl;
        return res;
    }
    
    string getsimilar(string str){
        int minn = INT_MAX;
        string res;
        for(int i = 0; i < 16; ++i){
            string target(2, getChar(i));
            //cout << target << ": " << distance(str, target) << endl;
            if(distance(str, target) < minn){
                minn = distance(str, target);
                res = target;
            }
        }
        return res;
    }
    
    int distance(string a, string b){
        int distance = pow((getNum(a[0]) - getNum(b[0])) * 16 + getNum(a[1]) - getNum(b[1]), 2);
        return distance;
    }
    
    
    int getNum(char ch){
        if(isdigit(ch))
            return ch - '0';
        else
            return ch - 'a' + 10;    
    }
    
    int getChar(int num){
        if(num < 10)
            return char('0' + num);
        else
            return char('a' + num - 10);
    }
    
    
};

int main(){
    Solution s;
    cout << s.similarRGB("#09f166") << endl;
    return 0;
}
