/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 28 20:54:15 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 有N种物品和一个容量为V的背包。第i种物品最多有n[i]件可用，每件费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

class Solution{
public:
    int MultipleBackPack(int V, vector<int>& c, vector<int>& w, vector<int>& n){
        // dp[i][j]: from first i items, make the cost exactly equal to V, the maximum of values in the bag
        // dp[i][j] = max(dp[i-1][j], dp[i-1][j-k * c[i]] + k * w[i] | 0 <= k <= n[i])
        vector<int> dp(V + 1, 0);


        for(int i = 0; i < c.size(); ++i)
        for(int j = V; j >= 0; --j)
        for(int k = 1; k <= n[i]; ++k){
            if(j - k * c[i] >= 0){
                dp[j] = max(dp[j], dp[j - k * c[i]] + k * w[i]);
            }
        }

        return dp.back();
    }


};

int main(){
    Solution s;
    vector<int> c {1,2,4,3};
    vector<int> w {2,4,1,5};
    vector<int> n {2,1,4,3};
    cout << s.MultipleBackPack(6, c, w, n) << endl;
    return 0;
}
