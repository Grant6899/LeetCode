#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
	string findContestMatch(int n) {
		vector<string> strvec;

		for (int i = 1; i <= n; i++) {
			strvec.push_back(std::to_string(i));
		}

		while (n > 1) {

			for (int i = 0; i < n / 2; i++) {
				strvec[i] = "(" + strvec[i] + "," + strvec[n - i - 1] + ")";
			}
			n /= 2;
		}
		
		return strvec[0];
	}

};

int main() {
	Solution s;

	cout << s.findContestMatch(128) << std::endl;

	return 0;
}