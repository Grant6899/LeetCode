/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 20 22:11:40 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        return recursion(n, true);
    }
    // return the left number of 1 - n starting from eliminting left to right
    int recursion(int n, bool isLeft) {
        if(n == 1) return n;
        if(!isLeft && (n % 2) == 0) {
            // eliminate all the even numbers
            // [1, 2, 3, 4, 5, 6] -> [1, 3, 5]
            // It is equivalent to consider the number left in [1, 2, 3] * 2 - 1
            return recursion(n / 2, !isLeft) * 2 - 1;
        } else {
            // eliminate all the odd numbers
            // [1, 2, 3, 4, 5, 6] -> [2, 4, 6]
            // It is equivalent to consider the number left in [1, 2, 3] * 2
            return recursion(n / 2, !isLeft) * 2;
        }
    }
};

int main(){
    Solution s;
    cout << s.lastRemaining(10) << endl;
    return 0;
}
