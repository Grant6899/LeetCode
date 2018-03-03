/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Mar  2 19:43:40 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
		int res = INT_MAX, num = 0;
		dfs(0, amount, coins, num, res);
        return res == INT_MAX? -1 : res;
    }
	
	void dfs(int index, int amount, vector<int>& coins, int& num, int& res){
		if(amount == 0){
			res = min(res, num);
            return;
        }
        
        if(index == coins.size())
            return;
        
		for(int i = amount / coins[index]; i >= 0; --i){
			if(amount - i * coins[index] >= 0){
				num += i;
				dfs(index + 1, amount - i * coins[index], coins, num, res);
				num -= i;
			}
		}
	}
};


int main(){
    vector<int> coins{186,419,83,408};
    Solution s;

    cout << s.coinChange(coins, 6249) << endl;
    
    return 0;
}
