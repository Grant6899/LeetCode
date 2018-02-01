/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 31 18:44:39 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;

        vector<int> dp0(prices.size(), 0), dp1(prices.size(), INT_MIN);

        dp0[0] = -prices[0];
        dp1[0] = 0;

        for(int i = 1; i < prices.size(); ++i){
            if(i - 2 >= 0)
                dp0[i] = max(dp0[i-1], dp1[i-2] - prices[i]);
            else
                dp0[i] = max(dp0[i-1], -prices[i]);
            dp1[i] = max(dp1[i-1], dp0[i-1] + prices[i]);
        }

       /* for(int p : dp0)
            cout << p <<' ';
        cout << endl;
        for(int p : dp1)
            cout << p <<' ';*/

        return dp1.back();
    }
};

int main(){
    
    Solution s;
    vector<int> vec{1,3,1,4,5};
    cout << s.maxProfit(vec) << endl;
    
    return 0;
}
