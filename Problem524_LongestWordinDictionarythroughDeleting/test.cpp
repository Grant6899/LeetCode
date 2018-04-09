/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  9 19:06:28 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
		auto com = [](string& s1, string& s2){ if(s1.size() != s2.size()) return s1.size() > s2.size(); else return s1 < s2;};
		
		sort(d.begin(), d.end(), com);
		
		for(auto& p : d)
			if(isMatch(s, p, 0, 0))
				return p;
		
		return "";
    }
	
	bool isMatch(string& s, string& p, int sp, int pp){
		if(pp == p.size())
			return true;
		
		if(sp == s.size())
			return false;
		
		if(s[sp] == p[pp])
			return isMatch(s, p, sp + 1, pp + 1);
		else
			return isMatch(s, p, sp + 1, pp);
	}
};

int main(){
    Solution s;
    vector<string> d{"ale","apple","monkey","plea"};
    cout << s. findLongestWord("abpcplea", d) << endl;
    return 0;
}
