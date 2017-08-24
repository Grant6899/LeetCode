#include<iostream>


class Solution {
public:
	int reverse(int x) {
		long long result = 0;
		long long original = x;
		
		while (abs(original) > 0) {
			result = result * 10 + original % 10;
			original /= 10;
		}
		if (result > INT_MAX || result < INT_MIN) return 0;
		return result;
	}
};

int main() {
	Solution s;

	std::cout << s.reverse(1534236469) << std::endl;

	return 0;
}