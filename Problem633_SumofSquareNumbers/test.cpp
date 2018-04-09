/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  9 19:12:25 2018
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c); ++i){
			int temp = sqrt(c - i * i);
			if(temp * temp == c - i * i)
				return true;
		}
		return false;
    }
};

int main(){
    Solution s;
    cout << s. judgeSquareSum(321) << endl;
    return 0;
}
