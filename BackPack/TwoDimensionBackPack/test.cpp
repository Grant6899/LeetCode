/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 28 21:40:27 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//对于每件物品，具有两种不同的费用；选择这件物品必须同时付出这两种代价；
//对于每种代价都有一个可付出的最大值（背包容量）。问怎样选择物品可以得到最大的价值。
//设这两种代价分别为代价1和代价2，第i件物品所需的两种代价分别为a[i]和b[i]。
//两种代价可付出的最大值（两种背包容量）分别为V和U。物品的价值为w[i]

class Solution{
public: 
    int BackPack01(int V1, int V2, vector<int>& c1, vector<int>& c2, vector<int>& w){
        // dp[i][j][k]: from first i items, make the cost1 exactly equal to j, the cost2 less than or equal to k, the maximum of values in the bag
        // dp[i][j][k] = max(dp[i-1][j], dp[i-1][j-c1[i]][k - c2[i]] + w[i])
        vector<vector<int>> dp(V1 + 1, vector<int>(V2 + 1, 0));

        
        for(int i = 0; i < w.size(); ++i)
        for(int j = V1; j >= 0; --j)
        for(int k = V2; k >= 0; --k){
            if(j - c1[i] >= 0 && k - c2[i] >= 0){
                dp[j][k] = max(dp[j][k], dp[j - c1[i]][k - c2[i]] + w[i]);
            }
        }
        
        return dp[V1][V2];
    }


};

int main(){
    Solution s;
    vector<int> c1 {1,2,4,2};
    vector<int> c2 {2,5,3,1};
    vector<int> w {2,4,1,4};
    cout << s.BackPack01(6, 3, c1, c2, w) << endl;
    return 0;
}

