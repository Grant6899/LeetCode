/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Apr  8 23:53:13 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<vector<double>> dp(K + 1, vector<double>(A.size() + 1, 0.0)); 
        // dp[i][j] -- split elements(until idx j) into i groups
        
        vector<double> sum(A.size() + 1, 0);

        double res = 0.0;
        for(int i = 1; i < A.size() + 1; ++i){
            sum[i] = sum[i-1] + A[i-1];
            dp[1][i - 1] = sum[i] / double(i);
            if(i == A.size()) res = max(res, dp[1][i-1]);
        }
        
        
        for(int i = 2; i <= K; ++i)
            for(int j = i - 1; j < A.size(); ++j){
                
                //cout << "calculating dp[" << i << "][" << j << "]:\n";
                for(int p = i - 2; p < j; ++p){
                    //cout << p << ":" << dp[i-1][p] << " " << (sum[j + 1] - sum[p + 1]) / (j + 1 - (p + 1)) << endl;
                    if(dp[i-1][p] + (sum[j + 1] - sum[p + 1]) / (j + 1 - (p + 1)) > dp[i][j]){
                        dp[i][j] = dp[i-1][p] + (sum[j + 1] - sum[p + 1]) / (j + 1 - (p + 1));
                        if(j == A.size() - 1) res = max(res, dp[i][j]);
                    }
                }
                //cout << endl;
            }

        return res;
    }
};

int main(){
	Solution s;
	std::vector<int> v{4,1,7,5,6,2,3};
	cout << s.largestSumOfAverages(v, 4) << endl;
	return 0;
}