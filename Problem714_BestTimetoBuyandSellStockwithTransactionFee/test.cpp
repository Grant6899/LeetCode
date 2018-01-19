/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 18 21:34:49 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        //s0 = profit having no stock
        //s1 = profit having 1 stock
        vector<int> s0{0}, s1{INT_MIN};

        for(int i = 0; i < prices.size();++i){
            s0.push_back(max(s0.back(), s1.back() + prices[i]));
            s1.push_back(max(s1.back(), s0.back() - prices[i] - 2));
        }
        return s0.back();
    }
};

int main(){

    vector<int> prices {1, 3, 2, 8, 4, 9};

    Solution s;
    cout << s.maxProfit(prices, 2) << endl;

    return 0;
}
