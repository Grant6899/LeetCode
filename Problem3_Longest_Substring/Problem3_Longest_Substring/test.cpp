
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		std::vector<int> flag(255, -1);
		int max_len = 0, last = -1;
		for (int i = 0; i < s.size(); ++i) {
			int last = std::max(flag[s[i]], last);
			int len = i - last;
			max_len = std::max(max_len, len);
			flag[s[i]] = i;
		}
		return max_len;
	}
};

int main() {
	Solution s;

	std::cout << s.lengthOfLongestSubstring("pwwkew") << std::endl;
	return 0;
}