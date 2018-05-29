/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:49:02 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)
            return 0;
        if(n == 1)
            return k;
        // considering last two posts
        int diff = k * (k-1);
        int same = k;


        for(int i = 2; i < n; i++){
            int temp = diff;
            diff = (diff + same) * (k-1);
            same = temp;
        }

        return diff + same;
    }
};

int main(){
    Solution s;
    cout << s.numWays(3, 2) << endl;
    return 0;
}
