#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string result = "";
		vector<string> bucket(numRows, "");

		int k = 2 * numRows - 2;

		for (int i = 0; i < s.size(); ++i) {
			int temp = i % k;
			
			if (temp > (k / 2)) continue;
			bucket[temp] += s[i];

			if (i % (k / 2) == 0) continue;
			int image = ((i / k) + 1)*k - temp;
			if  ( image < s.size()) bucket[temp] += s[((i / k) + 1)*k - temp];
		}

		for (int i = 0; i < bucket.size(); i++)
			result += bucket[i];
		return result;
	}
	
};

int main() {
	Solution s;
	std::cout << s.convert("ABC", 2) << std::endl;
	return 0;
}