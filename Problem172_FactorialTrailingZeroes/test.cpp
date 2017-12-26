/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 25 20:05:45 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0, num = 1;
        long long divisor = 5;
        while(num > 0){
            num = n / divisor;
            result += num;
            divisor *= 5;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout << s.trailingZeroes(1808548329) << endl;
    return 0;
}
