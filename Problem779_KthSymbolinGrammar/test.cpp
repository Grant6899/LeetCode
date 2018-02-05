/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Feb  3 22:57:58 2018
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1)
            return 0;

        if(K % 2)
            // K is odd
            return kthGrammar(N-1, (K + 1) / 2);
        else
            // K is even
            return kthGrammar(N, K - 1) == 0 ? 1 : 0;
    }
};

int main(){
    Solution s; 
    cout << s.kthGrammar(2, 1) << endl;
    return 0;
}
