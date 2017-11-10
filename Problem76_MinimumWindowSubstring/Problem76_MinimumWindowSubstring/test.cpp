#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> candidates;
		unordered_map<char, vector<int>> bound;

		for (int i = 0; i < t.size(); i++)
			if (candidates.find(t[i]) == candidates.end())
				candidates[t[i]] = 1;
			else
				candidates[t[i]]++;

		for (int i = 0; i < s.size(); i++) {

			if (candidates.find(s[i]) != candidates.end()) {
				candidates[s[i]]--;
				if (candidates[s[i]] == 0)
					candidates.erase(s[i]);

			}




		}


	}
};

int main() {

	Solution s;

	string S = "ADOBECODEBANC", T = "ABC";

	auto ans = s.minWindow(S, T);

	return 0;

}