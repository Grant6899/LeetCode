/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 25 19:02:59 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        // dp ([i])[j][k] - if among first i nums, using j nums can reach sum of k
        vector<vector<bool>> dp(A.size() + 1, vector<bool>(A.size() * 10000 + 1, false));
        int sum = 0;
        for (const auto& iter : A) {
            sum += iter;
        }
        
        dp[0][0] = true;
        for (int i = 0; i < A.size(); i++) {
            for (int j = i; j >= 0; j--) {
                for (int k = 0; k <= sum ;k++) {
                    
                    if (!dp[j][k]) 
                        continue; 
                    
                    int cur = k + A[i];
                    if (cur * (A.size() - j - 1) == (sum - cur) * (j + 1) && sum - cur != 0) { 
                        return true; 
                    }
                    dp[j + 1][cur] = true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums{9990, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30};
    cout << s. splitArraySameAverage(nums) << endl;
    return 0;
}
