/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 31 15:33:10 2017
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> passed(n, false);
        int sum = 1;
        int upper = sqrt(n);
        for (int i=3; i<n; i+=2) {
            if (!passed[i]) {
                sum++;
                //avoid overflow
                if (i>upper) continue;
                for (int j=i*i; j<n; j+=i)
                    passed[j] = true;
            }
        }
    return sum;
    }
};

int main(){
    Solution s;
    cout << s.countPrimes(25) << endl;
    return 0;
}
