/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 15:44:11 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        n = ((n & 0XFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
        return n;
    }
};

int main(){
    Solution s;
    cout << s.reverseBits(43261596) << endl;
    return 0;
}
