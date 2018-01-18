/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 20:42:23 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        n ^= n/2;
        return !(n & n+1);
    }
};

/*
Xor the number with itself shifted right once and check whether everything after the leading 1-bit became/stayed 1. Xor is 1 iff the bits differ, so we get 1-bits iff starting with the leading 1-bit, the bits alternate between 1 and 0.

    000101010 (42)
  ^ 000010101 
  = 000111111

*/

int main(){
    
    Solution s;

    cout << s.hasAlternatingBits(42) << endl;

    return 0;
}
