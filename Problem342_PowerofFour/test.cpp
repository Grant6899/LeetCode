/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 14:49:22 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        cout << (num > 0) << endl;
        cout << ((num & (num - 1)) == 0) << endl;
        cout << ((num & 0x55555555) == num) << endl;
        return (num > 0 && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num) );
    }
};

int main(){
    Solution s;

    cout << s.isPowerOfFour(16) << endl;

    return 0;
}

