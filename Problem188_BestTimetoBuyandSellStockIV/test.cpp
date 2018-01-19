/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 18 21:51:39 2018
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> prev(2 * k, 0), cur(2 * k, 0);

        for(int i = 0; i < 2 * k; ++i)
            if(i & 1) prev[i] = INT_MIN;

        for(int i = 0; i < prices.size(); ++i){
            for(int j = 0; j < 2 * k; ++j)
                if(j == 0)
                    cur[j] = max(prev[j], -prices[i]);
                else if(j & 1)
                    cur[j] = max(prev[j], prev[j-1] + prices[i]);
                else
                    cur[j] = max(prev[j], prev[j-1] - prices[i]);


            for(int j = 0; j < 2 * k; ++j)
                cout << cur[j] << " ";
            cout << endl;
            prev = cur;
        }
        
        int res = 0;
        for(int i = 0; i < 2*k;i++)
            if(i & 1) res = max(res, cur[i]);
        
        return res;
    }
};




int main(){
    
    Solution s;
    vector<int> nums {1,1,1,2,2,3};    
    cout << s.maxProfit(2,nums);
    return 0;
}
