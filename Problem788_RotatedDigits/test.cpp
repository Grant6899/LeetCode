/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Feb 25 08:31:19 2018
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        for(int i = 0; i <= N; ++i){
            if(isValid(i))
                res++;
        }
        return res;
    }

    bool isValid(int X){
        string temp = to_string(X);
        bool find = false;
        for(char ch : temp){
            if(ch == '3' || ch == '4' || ch == '7')
                return false;
            if(ch == '2' || ch == '5' || ch == '6' || ch =='9')
                find = true;
        }

        if (find) return true;
        else return false;
    }
};

int main(){
    Solution s;

    cout << s.rotatedDigits(100) << endl;

    return 0;
}
