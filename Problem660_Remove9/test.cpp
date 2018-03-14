/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 13 20:47:43 2018
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int newInteger(int n) {

		string str = "";
		while(n > 0){
			str += char('0' + n % 9);
			n /= 9;
		}

		reverse(str.begin(), str.end());
		return stoi(str);

    }
};

int main(){
    Solution s;
    cout << s.newInteger(81) << endl;
    return 0;
}
