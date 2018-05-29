/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:11:09 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 0) return false;
        int sum = 1;
        for(int i = 2; i < sqrt(num); ++i){
            if(num % i == 0)
                sum += i + num / i;
        }

        if(num == sqrt(num)* sqrt(num))
            sum += sqrt(num);

        return sum == num;
    }
};

int main(){
    Solution s;
    cout << s. checkPerfectNumber(100) << endl;
    return 0;
}
