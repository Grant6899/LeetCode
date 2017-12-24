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
        if(s.size() == 0 || s[0] == '0')
            return 0;
        
        if(s[0] != '0')
            return 1;

        dp[0] = dp[1] = 1;

        for(int i = 2; i <= s.size(); ++i){
            if( valid(s[i-1]) && valid(s[i-2], s[i-1]) )
                dp[i] = dp[i-1] + dp[i-2];
            if( !valid(s[i-1]) && valid(s[i-2], s[i-1]) )
                dp[i] = dp[i-2];
            if( valid(s[i-1]) && !valid(s[i-2], s[i-1]) )
                dp[i] = dp[i-1];
            if( !valid(s[i-1]) && !valid(s[i-2], s[i-1]) )
                return 0;
        }
        return dp[s.size()];
    }

private:
    bool valid(char ch1, char ch2){
        return (ch1 == '1' || (ch1 == '2' && ch2 <= '6'));
    }

    bool valid(char ch){
        return ch != '0';
    }
};

int main(){
    Solution s;
    cout << s.numDecodings("123") << endl;

    return 0;
}
