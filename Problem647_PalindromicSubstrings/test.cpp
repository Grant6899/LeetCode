/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan 30 22:52:26 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        for(int i = 0; i < s.size(); ++i)
        for(int j = 0; j < s.size(); ++j)
            if(i > j) dp[i][j] = true;
            
        int res = 0;
        for(int i = 1; i <= s.size(); ++i)
        for(int j = 0; j <= s.size() - i; ++j){
            if( (j + i - 2 < j + 1 || dp[j + 1][j + i - 2]) && s[j] == s[j + i - 1]){
                dp[j][j + i - 1] = true;
                res++;
                cout << j << ' ' << j + i - 1 << endl;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.countSubstrings("aaa") << endl;
    return 0;
}
