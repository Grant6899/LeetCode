/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 18 23:16:19 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int original = n;
        while(n > 0){
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        next_permutation(digits.begin(), digits.end());

        int res = 0;
        for(int i = 0; i < digits.size();++i){
            res*=10;
            res += digits[i];
        }
        
        if(res > original)
            return res;
        else 
            return -1;
    }
};

int main(){
    Solution s;

    cout << s.nextGreaterElement(21) << endl;

    return 0;
}
