#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix = "";
		for (int idx = 0; strs.size() > 0; idx++) {
			for (int i = 0; i < strs.size(); i++) {
				if (idx > strs.size() || (i > 0 && strs[i][idx] != strs[i - 1][idx]))
					return prefix;
			}
			prefix += strs[0][idx];
		}
		return prefix;
	}
};

int main() {
	Solution s;
	vector<string> vec{ "123", "12345", "12" };
	std::cout << s.longestCommonPrefix(vec) << std::endl;

	return 0;
}