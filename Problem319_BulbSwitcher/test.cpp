/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 30 20:44:09 2017
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

/* the odd-operation numbers:

1. as for primes, they only have 1 and itself as their factors, even-operation numbers;
2. as for non-primes, normally they will have different pairs of factors like 12 whose factors are (1, 12), (3, 4), (2, 6) - 6 different factors, also even-operation numbers;
3. but among non-primes, there are some special numbers, perfect square numbers like 9 whose factors are (1, 9) and (3, 3) - odd-operation numbers, which means there will be only three different numbers that will affect the current bulb and result in bulb-on state!
*/



class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main(){
    Solution s;
    cout << s.bulbSwitch(14) << endl;
    return 0;
}
