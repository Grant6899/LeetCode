#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {

		if (needle.size() > haystack.size())
			return -1;

		for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
			bool flag = true;
			for (int j = 0; j < needle.size(); j++) {
				if (haystack[i + j] != needle[j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				return i;
		}

		return -1;

	}
};

int main() {
	Solution s;

	auto ans = s.strStr("abb", "31");

	std::cout << ans << std::endl;

	return 0;
}