/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Mar 17 20:12:01 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
		unordered_map<string, vector<string>> dic;
		vector<vector<string>> res;

		for(string str : strings)
			dic[norm(str)].push_back(str);

		for(auto ele : dic)
			res.push_back(ele.second);

		return res;
    }

	string norm(string str){
		int offset = str[0] - 'a';
		string res = "";
		for(char ch : str){
			res += char(ch - offset < 'a'? ch - offset + 26 : ch - offset);
		}
		return res;
	}


};

int main(){
    Solution s;
    vector<string> strs{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    auto ans = s.groupStrings(strs);
    for(auto ss : ans){
        for(auto sss : ss)
            cout << sss << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
