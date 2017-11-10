#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> res(1, 1);
		vector<int> index(primes.size(), 0);
		
		while (res.size() < n) {
			vector<int> tmp(primes.size(), 0);
			for (int i = 0; i < primes.size(); i++)
				tmp[i] = res[index[i]] * primes[i];
				
			int mn = INT_MAX, minindex = 0;
			
			for (int i = 0; i < primes.size(); i++) {
				if (mn > tmp[i]) 
					mn = tmp[i];
			}

			for (int i = 0; i < primes.size(); i++) {
				if (mn == tmp[i])
					index[i]++;
			}
			res.push_back(mn);
		}
		return res.back();
	}
};

int main() {
	Solution s;

	vector<int> p  { 2, 3, 5 };
	std::cout << s.nthSuperUglyNumber(11, p) << std::endl;
	return 0;
}