/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Feb  3 12:47:34 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
		vector<int> dp(pairs.size(), 1);

        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){ return a[0] == b[0]? a[1] < b[1] : a[0] < b[0];});

		for(int i = 0; i < pairs.size(); ++i){
			for(int j = 0; j < i; ++j)
				if(pairs[j][1] < pairs[i][0])
					dp[i] = max(dp[i], dp[j] + 1);
		}

		return dp.back();
    }
};

int main(){
    Solution s;
    vector<vector<int>> p {{1,2}, {2,3}, {3,4}};
    cout << s.findLongestChain(p) << endl;
    return 0;
}
