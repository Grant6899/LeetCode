/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Apr  4 23:27:01 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty())
            return 0;

        auto com = [](pair<int, int>& a, pair<int, int>& b){ return a.first == b. first? a.second < b.second : a.first < b.first ;};

        sort(envelopes.begin(), envelopes.end(), com);


        vector<int> dp(envelopes.size(), 1);
        int res = 1;
        for(int i = 0; i < envelopes.size(); ++i)
            for(int j = 0; j < i; j++){
                if(dp[j] + 1 > dp[i] && envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second){
                    dp[i] = dp[j] + 1;
                    res = max(res, dp[i]);
                }
            }

        return res;
    }
};

int main(){
    Solution s;
    vector<pair<int, int>> envelopes{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << s.maxEnvelopes(envelopes) << endl;
    return 0;
}
