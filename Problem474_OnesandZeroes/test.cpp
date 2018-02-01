/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  1 18:27:46 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

		vector<int> c0(strs.size(), 0), c1(strs.size(), 0);

		for(int i = 0; i < strs.size(); ++i){
			for(char ch : strs[i])
				if(ch == '0')
					c0[i]++;
				else
					c1[i]++;
		}

        /*cout << "c0: ";
		for(int x : c0)
			cout << x << " ";
		cout << "\nc1: ";
		for(int x : c1)
			cout << x << " ";*/
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));


		for(int i = 0; i < strs.size(); ++i)
			for(int j = m; j >= 0; --j)
				for(int k = n; k >= 0; --k){
					if(j - c0[i] >= 0 && k - c1[i] >= 0)
						dp[j][k] = max(dp[j][k], dp[j-c0[i]][k-c1[i]] + 1);
				}

		return dp[m][n];
    }


};

int main(){
    Solution s;
    vector<string> strs {"10","0001","111001","1","0"};
    cout << s.findMaxForm(strs, 5, 3) << endl;
    return 0;
}
