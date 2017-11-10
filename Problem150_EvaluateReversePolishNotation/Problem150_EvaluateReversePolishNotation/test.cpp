#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {

		vector<string> stack = {};

		for (auto it = tokens.begin(); it < tokens.end(); it++) {

			if (*it == "+") {
				int operand_2 = stoi(stack.back());
				stack.pop_back();
				int operand_1 = stoi(stack.back());
				stack.pop_back();
				stack.push_back(to_string(operand_1 + operand_2));
			}
			else if (*it == "-") {
				int operand_2 = stoi(stack.back());
				stack.pop_back();
				int operand_1 = stoi(stack.back());
				stack.pop_back();
				stack.push_back(to_string(operand_1 - operand_2));
			}
			else if (*it == "*") {
				int operand_2 = stoi(stack.back());
				stack.pop_back();
				int operand_1 = stoi(stack.back());
				stack.pop_back();
				stack.push_back(to_string(operand_1 * operand_2));
			}
			else if (*it == "/") {
				int operand_2 = stoi(stack.back());
				stack.pop_back();
				int operand_1 = stoi(stack.back());
				stack.pop_back();
				stack.push_back(to_string(operand_1 / operand_2));
			}
			else
				stack.push_back(*it);
		}

		return stoi(stack.back());
	}
};


int main() {
	Solution s;


	vector<string> exp{ "4", "13", "5", "/", "+" };

	auto ans = s.evalRPN(exp);

	std::cout << ans << std::endl;
	return 0;
}