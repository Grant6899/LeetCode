/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:04:51 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long i=0,k=0;
        while(k<num){
            i++;
            k = i*i;
        }

        if(k==num) return true;

        return false;
    }
};


int main(){
    Solution s;
    cout << s.isPerfectSquare(100) << endl;
    return 0;
}
