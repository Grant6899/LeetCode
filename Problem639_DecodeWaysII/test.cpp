/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Apr 11 22:53:55 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int64_t> dp(s.size(), 0);

        if(s[0] == '0')
            dp[0] = 0;
        else if(s[0] == '*')
            dp[0] = 9;
        else
            dp[0] = 1;

        for(int i = 1; i < s.size(); ++i){
            if(s[i] == '*'){
                if(s[i-1] == '1')
                    dp[i] = dp[i-1] * 9 + (i - 2 >= 0 ? dp[i-2] : 1) * 9;
                else if(s[i-1] == '2')
                    dp[i] = dp[i-1] * 9 + (i - 2 >= 0 ? dp[i-2] : 1) * 6;
                else if(s[i-1] == '*'){
                    if(s[i] == '*')
                        dp[i] = dp[i-1] * 9 + (i - 2 >= 0 ? dp[i-2] : 1) * 15;
                    else if(s[i] <= '6')
                        dp[i] = dp[i-2] * 2 + dp[i-1] * 9;
                    else
                        dp[i] = dp[i-2] + dp[i-1] * 9;
                }
                else
                    dp[i] = dp[i-1] * 9;
            }
            else if(s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2')
                    dp[i] = (i - 2 >= 0 ? dp[i-2] : 1);
                else if(s[i-1] == '*')
                    dp[i] = (i - 2 >= 0 ? dp[i-2] : 1) * 2;
                else
                    dp[i] = 0;
            }
            else{
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] > '0' && s[i] <= '6' ))
                    dp[i] = (i - 2 >= 0 ? dp[i-2] : 1) + dp[i-1];
                else if(s[i-1] == '*')
                    if(s[i] <= '6')
                        dp[i] = (i - 2 >= 0 ? dp[i-2] : 1) * 2 + dp[i-1];
                    else
                        dp[i] = (i - 2 >= 0 ? dp[i-2] : 1) + dp[i-1];
                else
                    dp[i] = dp[i-1];
            }

            dp[i] %= 1000000007;
        }

        return dp.back();
    }
};

int main(){
    Solution s;
    cout << s. numDecodings("12*") << endl;
    return 0;
}
