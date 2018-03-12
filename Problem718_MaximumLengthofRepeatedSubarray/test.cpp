/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 11 18:26:29 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        int res = 0;

        // dp[i][j] - the max common subarry length ends at A[i] and B[j]
        for(int i = 0; i < A.size(); ++i)
            for(int j = 0; j < B.size(); ++j){
                if(A[i] == B[j])
                    dp[i][j] = (i - 1 >= 0 && j - 1 >= 0)? dp[i-1][j-1] + 1 : 1;
                res = max(res, dp[i][j]);
            }

        /*for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < B.size(); ++j)
                cout << dp[i][j] << " ";
            cout << endl;
        }*/


        return res;
    }
};

int main(){
    vector<int> A{1,2,3,2,1}, B{3,2,1,4,7};

    Solution s;

    cout << s.findLength(A, B) << endl;
    return 0;
}
