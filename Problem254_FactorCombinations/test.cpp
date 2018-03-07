/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 18:41:12 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
		int pro = 1;
		vector<int> cur;
		vector<vector<int>> res;
		dfs(n, cur, res);
		return res;
    }
	
	void dfs(int pro, vector<int>& cur, vector<vector<int>>& res){
		if(pro == 1 && cur.size() > 1){
			res.push_back(cur);
			return;
		}
		
		for(int i = cur.empty()? 2 : cur.back(); i <= pro; ++i){
			if(pro % i == 0){
				cur.push_back(i);
				dfs(pro / i, cur, res);
				cur.pop_back();
			}
		}
	}
};

int main(){
    Solution s;
    
    auto ans = s.getFactors(10);

    return 0;
}
