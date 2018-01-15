/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 15:37:52 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // mask is used to trim leading zeros
        int mask = ~0;

        while(num & mask)
            mask <<= 1;

        return (~num & ~mask);
    }
};

int main(){
    Solution s;

    cout << s.findComplement(5) << endl;
    return 0;
}
