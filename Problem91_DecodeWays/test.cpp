/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 24 14:30:47 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= s.size(); ++i){
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                dp[i] = dp[i-1] + dp[i-2];
            }
            else
                dp[i] = dp[i-1];
        }
        
        return dp[s.size()];
    }
};

int main(){
    Solution s;
    cout << s.numDecodings("123") << endl;

    return 0;
}
