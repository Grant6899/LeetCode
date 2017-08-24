#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<vector<string>> code = {
			{},
			{},
			{"a","b","c"},
			{"d","e","f"},
			{"g","h","i"},
			{"j","k","l"},
			{"m","n","o"},
			{"p","q","r","s"},
			{"t","u","v"},
			{"w","x","y","z"}
		};

		vector<string> result;

		string current;
		DFS(code, result, 0, digits, current);
		return result;
	}

	void DFS(const vector<vector<string>>& code, vector<string>& result, int i, string digits, string& current) {
		auto t = code[digits[i] - '0'].end();
		for (auto it = code[digits[i] - '0'].begin(); it < code[digits[i] - '0'].end(); it++) {
			current += *it;
			if (current.size() == digits.size())
				result.push_back(current);
			else
				DFS(code, result, current.size(), digits, current);
			current.pop_back();
		}
	}

};

int main() {
	Solution s;
	string str = "23";
//	std::cout << s.longestCommonPrefix(vec) << std::endl;

	auto ans = s.letterCombinations(str);

	return 0;
}