/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 15:53:10 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = ((n & 0xAAAAAAAA) >> 1) + (n & 0x55555555);  
        n = ((n & 0xCCCCCCCC) >> 2) + (n & 0x33333333);  
        n = ((n & 0xF0F0F0F0) >> 4) + (n & 0x0F0F0F0F);  
        n = ((n & 0xFF00FF00) >> 8) + (n & 0x00FF00FF);
        n = ((n & 0xFFFF0000) >> 16) + (n & 0x0000FFFF);
        return n;
    }
};

int main(){
    Solution s;
    cout << s.hammingWeight(11) << endl;
    return 0;
}
