/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 28 17:20:36 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。

class Solution{
public: 
    int BackPack01(int V, vector<int>& c, vector<int>& w){
        // dp[i][j]: from first i items, make the cost exactly equal to V, the maximum of values in the bag
        // dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]] + w[i])
        vector<int> dp(V + 1, 0);

        
        for(int i = 0; i < c.size(); ++i)
        for(int j = V; j >= 0; --j){
            if(j - c[i] >= 0){
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
            }
        }
        
        return dp.back();
    }


};

int main(){
    Solution s;
    vector<int> c {1,2,4,2};
    vector<int> w {2,4,1,4};
    cout << s.BackPack01(6, c, w) << endl;
    return 0;
}
