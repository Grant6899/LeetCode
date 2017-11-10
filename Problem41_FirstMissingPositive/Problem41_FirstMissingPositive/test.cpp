#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:
	int firstMissingPositive(vector<int> A){
		int n = A.size();
		for (int i = 0; i < n; ++i)
			while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
				swap(A[i], A[A[i] - 1]);

		for (int i = 0; i < n; ++i)
			if (A[i] != i + 1)
				return i + 1;

		return n + 1;
	}
};

int main() {

	Solution s;

	vector<int> nums { 3,4,-1,1 };

	auto ans = s.firstMissingPositive(nums);

	return 0;
}