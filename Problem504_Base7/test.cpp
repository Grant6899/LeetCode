/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 22 20:17:32 2018
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string res;
        if (num == 0)
            return "0";

        string sign = num < 0? "-" : "";
        num = abs(num);
        while(num > 0){
            res += to_string(num % 7);
            num /= 7;
        }

        reverse(res.begin(), res.end());
        return sign + res;
    }
};

int main(){
    Solution s;
    cout << s. convertToBase7(133) << endl;
    return 0;
}
