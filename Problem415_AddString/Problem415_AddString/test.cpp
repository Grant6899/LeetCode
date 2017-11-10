#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {

		std::reverse(num1.begin(), num1.end());
		std::reverse(num2.begin(), num2.end());

		int i = 0, j = 0, add = 0;

		vector<int> sum(5101, 0);

		while (i < num1.size() || i < num2.size() || add > 0) {
			if (i >= num1.size() && i >= num2.size()) {
				sum[i] += add;
				add = sum[i] / 10;
				sum[i] %= 10;
			}
			else if (i >= num1.size()) {
				sum[i] += (num2[i] - '0') + add;
				add = sum[i] / 10;
				sum[i] %= 10;
			}
			else if (i >= num2.size()) {
				sum[i] += (num1[i] - '0') + add;
				add = sum[i] / 10;
				sum[i] %= 10;
			}
			else {
				sum[i] += (num1[i] - '0') + (num2[i] - '0') + add;
				add = sum[i] / 10;
				sum[i] %= 10;
			}
			i++;
		}

		string result = "";

		for (int i = 0; i <= max(num1.size(), num2.size()) + 1; i++)
			result.push_back((char)(sum[i] + '0'));

		std::reverse(result.begin(), result.end());

		while (result.size() > 1 && result[0] == '0')
			result.erase(0, 1);

		return result;

	}
};

int main() {

	Solution s;

	string s1 = "1", s2 = "9";

	auto ans = s.addStrings(s1, s2);

	std::cout << ans << std::endl;

	return 0;
}