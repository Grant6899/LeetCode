#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (x > 0)	return std::exp( n * std::log(x) );
		else if (x == 0) return 0;
		else {
			double y = -x;
			if ( n % 2 != 0) return - std::exp(n * std::log(y));
			else return std::exp(n * std::log(y));
		}

	}
};
int main() {
	Solution s;

	std::cout << s.myPow(-13.62608, 4) << endl;
	return 0;
}