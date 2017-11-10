#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {

		vector<long long> product(10000, 0);

		std::reverse(num1.begin(), num1.end());
		std::reverse(num2.begin(), num2.end());

		int add = 0;

		for (int i = 0; i < num1.size(); ++i)
			for (int j = 0; j < num2.size(); ++j)
				product[i + j] += (num1[i] - '0') * (num2[j] - '0');

		int x = 1;

		for (int i = 0; i <= num1.size() + num2.size(); i++) {

			product[i] += add;
			add = product[i] / 10;
			product[i] %= 10;

		}

			
		string result = "";

		for (int i = num1.size() + num2.size(); i >= 0; i--)
			result.push_back((char)('0' + product[i]));

		while (result.size() > 1 && result[0] == '0')
			result.erase(0, 1);

		return result;
	}
};


int main() {

	Solution s;

	string s1 = "9", s2 = "0";

	auto ans = s.multiply(s1, s2);

	std::cout << ans << std::endl;

	return 0;
}