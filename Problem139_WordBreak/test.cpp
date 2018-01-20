/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 19 23:17:28 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic;
        for(auto ele : wordDict)
            dic.insert(ele);

        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for(int i = 0; i <= s.size();++i){
            
            for( int j = i-1; j >= 0; --j){
                if(dp[j] && dic.find(s.substr(j, i-j)) != dic.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    
    }
};

int main(){

    string str = "leetcode";
    vector<string> dict  {"leet", "code"};

    Solution s;

    cout << s.wordBreak(str, dict) << endl;

    return 0;
}
