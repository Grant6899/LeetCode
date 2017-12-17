/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 16 18:00:03 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        if( A.size() < 3)
            return 0;

        vector<int> dp(A.size(), 0);
                
        if( A[2] - A[1] == A[1] - A[0] )
            dp[2] = 1;
            
        result+=dp[2];
        for(int i = 3; i < A.size(); ++i){
            if( A[i] - A[i-1] == A[i-1] - A[i-2] )
                dp[i] = dp[i-1] + 1;
            result+=dp[i];
        }
        return result;
    }
};

int main(){
    
    vector<int> A {1,2 ,3, 4, 5};
    Solution s;
    cout << s.numberOfArithmeticSlices(A) << endl;
    return 0;
}
