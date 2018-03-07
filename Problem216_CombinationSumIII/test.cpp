/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 19:04:06 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        int sum = 0;
        dfs(cur, sum, k, n, res);
        return res;
    }


    void dfs(vector<int>& cur, int& sum, int k, int n, vector<vector<int>>& res){
        if(cur.size() == k && sum == n){
            res.push_back(cur);
            return;
        }

        for(int i = cur.empty()? 1 : cur.back() + 1; i <= min(9, n - sum); ++i){
            cur.push_back(i);
            sum += i;
            dfs(cur, sum, k, n, res);
            sum -= i;
            cur.pop_back();
        }
    }

};

int main(){
    Solution s;
    auto ans = s.combinationSum3(3, 10);
    for(auto a : ans){
        for(int b : a)
            cout << b << " ";
        cout << endl;
    }
    return 0;
}
