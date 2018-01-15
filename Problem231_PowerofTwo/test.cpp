/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 15:55:04 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && (n & (n - 1)) == 0);
    }
};

int main(){
    Solution s;
    cout << s.isPowerOfTwo(4) << endl;
    return 0;
}
