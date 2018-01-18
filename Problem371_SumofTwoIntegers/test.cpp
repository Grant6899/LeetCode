/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 21:04:28 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;

        while (b != 0)
        {
            sum = a ^ b;//calculate sum of a and b without thinking the carry
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }

        return sum;
    }
};

int main(){
    Solution s;
    cout << s.getSum(5, 3) << endl;

    return 0;
}
