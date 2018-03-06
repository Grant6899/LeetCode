/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:21:09 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
		if(s.size() == t.size())
			return equalcase(s, t);

		if(s.size() - t.size() == 1)
			return longercase(s, t);
		else if(t.size() - s.size() == 1)
			return longercase(t, s);

		return false;
    }

	bool equalcase(string s, string t){
		int diff_cnt = 0;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] != t[i]) diff_cnt++;
			if(diff_cnt > 1)
				return false;
		}
		return diff_cnt == 1? true : false;
	}

	bool longercase(string s, string t){

		for(int i = 0; i < s.size(); ++i){
			if(s.substr(0, i) == t.substr(0, i) && s.substr(i + 1) == t.substr(i))
				return true;
		}
		return false;
	}
};

int main(){
    Solution s;
    cout << s.isOneEditDistance("abc", "ab") << endl;
    return 0;
}
