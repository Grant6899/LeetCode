/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 13 18:33:43 2018
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int smallestFactorization(int a) {
        string str = "";

		for(int i = 9; i > 1; --i){
			if(a < 10) break;
			while(a % i == 0){
				if(a < 10) break;
				a /= i;
				str += char('0' + i);
				//cout << i << ", " << a << endl;
			}
		}
		if(a >= 10)
            return 0;
		str += char('0' + a);

        if(str.size() > 9)
            return 0;
		reverse(str.begin(), str.end());

		return stoi(str);
    }
};

int main(){
    Solution s;
    cout << s. smallestFactorization(100) << endl;
    return 0;
}
