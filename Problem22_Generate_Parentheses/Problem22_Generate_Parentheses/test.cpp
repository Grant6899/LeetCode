#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;



class Solution {

public:
	vector<string> generateParenthesis(int n) {

		vector<string> result;
		string current = "";

		find(0, 0, 0, current, result, n);
		
		return result;
	}

	void find(int m, int left, int right, string& current, vector<string>& result, int pair) {

		if (m == 2*pair -1) {
			current.push_back(')');
			result.push_back(current);
			current.pop_back();
			return;
		}


		for (int i = 0; i < 2; i++) {
			if (i == 0 && left < pair) {
				current.push_back('(');
				find(m + 1, left + 1, right, current, result, pair);
				current.pop_back();
			}
			else if (i == 1 && left > right) {
				current.push_back(')');
				find(m + 1, left, right + 1, current, result, pair);
				current.pop_back();
			}
		}

	}


};



int main() {
	Solution s;


	auto ans = s.generateParenthesis(4);

	return 0;
}