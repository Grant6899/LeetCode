#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;


class Solution {
public:
	int romanToInt(string s) {
		vector<int> num;

		for (int i = 0; i < s.size();++i) {
			switch (s[i]) {
			case 'I': num.push_back(1); break;
			case 'V': num.push_back(5); break;
			case 'X': num.push_back(10); break;
			case 'L': num.push_back(50); break;
			case 'C': num.push_back(100); break;
			case 'D': num.push_back(500); break;
			case 'M': num.push_back(1000); break;
			}
		}

		long long result = num.back();

		for (auto it = num.end() - 1; it > num.begin(); --it) {
			if (*(it - 1) < *it) result -= *(it - 1);
			else result += *(it - 1);
		}
		return result;
	}
};
int main() {
	Solution s;

	std::cout << s.romanToInt("CXXII") << std::endl;

	return 0;
}