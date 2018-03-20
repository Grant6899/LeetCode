/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 19 22:25:30 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
		vector<int> compressed;
		int counter = 1;
		for(int i = 1; i <= s.size(); ++i){
			if(s[i] == s[i-1])
				counter++;
			else{
				compressed.push_back(counter);
				counter = 1;
			}
		}

		/*for(int a : compressed)
			cout << a << ' ';
		cout << endl;*/

		int res = 0;
		for(int i = 1; i < compressed.size(); ++i)
				res += min(compressed[i-1], compressed[i]);

		return res;
    }
};

int main(){
    Solution s;
    cout << s. countBinarySubstrings("101001") << endl;
    return 0;
}
