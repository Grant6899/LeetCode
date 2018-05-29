/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:38:49 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();

		int sum = 0, F = 0;

		for(int i = 0; i < len; ++i){
			sum += A[i];
			F += i * A[i];
		}

		int res = F;
		for(int i = 0; i < len - 1; ++i){
			F = F + len * A[i] - sum;
			res = max(res, F);
		}
		return res;
    }
};

int main(){
    Solution s;
    vector<int> A{1, 2, 3, 4};
    cout << s. maxRotateFunction(A) << endl;
    return 0;
}
