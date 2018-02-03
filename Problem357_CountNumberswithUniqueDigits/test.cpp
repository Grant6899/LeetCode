/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Feb  3 12:45:38 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
		vector<int> count(11, 0);

        count[0] = 1;
		count[1] = 9;
		count[2] = 9 * 9;
		count[3] = 9 * 9 * 8;
		count[4] = 9 * 9 * 8 * 7;
		count[5] = 9 * 9 * 8 * 7 * 6;
		count[6] = 9 * 9 * 8 * 7 * 6 * 5;
		count[7] = 9 * 9 * 8 * 7 * 6 * 5 * 4;
		count[8] = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3;
		count[9] = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2;
		count[10] = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;

		long res = 0;
		for(int i = 0; i <= n; ++i)
			res += count[i];
		return res;
    }
};


int main(){
    Solution s;
    cout << s.countNumbersWithUniqueDigits(5) << endl;
    return 0;
}
