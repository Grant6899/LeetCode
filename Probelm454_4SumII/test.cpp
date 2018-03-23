/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 22 19:47:26 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size();
		
		
		unordered_map<int, int> sumAB, sumCD;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				sumAB[A[i] + B[j]]++;
			
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				sumCD[C[i] + D[j]]++;
			
		int res = 0;
		for(auto x : sumAB){
			if(sumCD.find(-x.first) != sumCD.end())
				res += x.second * sumCD[-x.first];
		}
		
		return res;
    }
};

int main(){
    vector<int> n1{1, 2}, n2{-2, -1}, n3{-1, 2}, n4{0, 2};
    Solution s;
    cout << s. fourSumCount(n1, n2, n3,n4) << endl;
    return 0;
}
