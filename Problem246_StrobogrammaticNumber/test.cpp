/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:44:07 2018
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
		map<char, char> mapping;
        mapping['0'] = '0';
		mapping['1'] = '1';
		mapping['8'] = '8';
		mapping['6'] = '9';
		mapping['9'] = '6';

        for(int i = 0; i < num.size(); ++i){
			if(mapping[num[i]] == num[num.size() - 1 - i])
				continue;
			else
				return false;
		}
		return true;
    }
};

int main(){
    Solution s;
    cout << s.isStrobogrammatic("321") << endl;
    return 0;
}
