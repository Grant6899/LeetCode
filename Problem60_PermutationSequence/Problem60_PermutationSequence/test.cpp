#include<iostream>
#include<vector>
#include<string>


using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {

		string result = "";

		vector<char> dic {};

		for (int i = 1; i <= n; i++) 
			dic.push_back(char(i + '0'));
		

		int num = n, index = 0;
		k--;
		while (result.size() < n) {

			index = k / factorial(num - 1);
			k %= factorial(num - 1);
			result.push_back(dic[index]);
			dic.erase(dic.begin() + index);
			num--;
				
		}

		return result;
	}

private:
	int factorial(int x) {
		int result = 1;
		if (x == 0 || x == 1)
			return result;
		else
			for (int i = 2; i <= x; i++)
				result *= i;
		return result;
	}
};

int main() {
	Solution s;

	for (int i = 1; i <= 6;i++ )
		std::cout << s.getPermutation(3, i)<< std::endl;
	return 0;
}