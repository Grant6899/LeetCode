#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
	bool isValid(string s) {

		std::vector<char> stack{ '0' };

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				stack.push_back(s[i]);
			}
			else {
				if ( (s[i] == ')' && stack.back() == '(') || (s[i] == ']' && stack.back() == '[') || (s[i] == '}' && stack.back() == '{'))
					stack.pop_back();
				else
					return false;
			}
		}

		if (stack[0] == '0' && stack.size() == 1) return true;
		else return false;
}

};

int main() {
	Solution s;

	std::cout << std::boolalpha<< s.isValid("[") << std::endl;

	return 0;
}