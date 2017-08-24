#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;


class Solution {
public:
	int divide(int dividend, int divisor) {
		if (!divisor || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;

		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

		int quotient = 0;
		
		long long abdividend = labs(dividend);
		long long abdivisor = labs(divisor);

		while (abdividend >= abdivisor) {
			long long temp = abdivisor, power = 0;
			while (abdividend > (temp << 1)) {
				temp <<= 1;
				power++;
			}
			abdividend -= temp;
			quotient += pow(2, power);
		}
		
		return sign == 1? quotient : -quotient;
	}



};


int main() {
	Solution s;

	auto ans = s.divide(INT_MIN, 1);

	std::cout << ans << std::endl;

	return 0;
}