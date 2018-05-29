/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:47:01 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.size() + s2.size() != s3.size())
            return false;
        
		vector<set<pair<int, int>>> dp(s3.size() + 1);
		
		dp[0].insert({-1, -1});
		
		for(int i = 1; i <= s3.size(); ++i){
			for(auto idx_pair : dp[i-1]){
                //cout << idx_pair.first << ", " << idx_pair.second << endl;
				if(s1[idx_pair.first + 1] == s3[i-1])
					dp[i].insert({idx_pair.first + 1, idx_pair.second});
				
				if(s2[idx_pair.second + 1] == s3[i-1])
					dp[i].insert({idx_pair.first, idx_pair.second + 1});
			}
            //cout << endl;
        }
        
		return !dp[s3.size()].empty();
    }
};

int main(){
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    return 0;
}
