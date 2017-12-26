/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 25 19:26:42 2017
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(auto it = s.begin(); it < s.end(); ++it){
            result = result * 26 + *it - 'A' + 1;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout << s.titleToNumber("AB") << endl;
    return 0;
}

