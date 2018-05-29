/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:05:52 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int len = 2;

        int res = 1;
        while(N / len >= 1 && (N / (double)len) > (len / 2) ){
            if ((N * 2) % len == 0){
                if(len % 2 == 0 && ((N * 2) / len) % 2 == 1)
                    res++;
                if(len % 2 == 1 && ((N * 2) / len) % 2 == 0)
                    res++;
                //cout << len << endl;
            }

            len++;
        }
        return res;
    }

    int sum(int st, int len){
        return len * (st + st + len - 1) / 2;
    }

};

int main(){
    Solution s;
    cout << s. consecutiveNumbersSum(40) << endl;
    return 0;
}
