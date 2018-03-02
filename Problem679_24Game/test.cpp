/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:41:19 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
		auto start = nums;
		sort(nums.begin(), nums.end());

		do{
			if(dfs(nums))
				return true;
		}while(next_permutation(nums.begin(), nums.end()));

        return false;
    }

private:
	bool dfs(vector<int>& nums){
		double a = nums[0], b = nums[1], c = nums[2], d = nums[3];

		if(dfs(a + b, c, d) || dfs(a - b, c, d) || dfs(a * b, c, d) || b && dfs(a / b, c, d)) return true;
		if(dfs(a, b + c, d) || dfs(a, b - c, d) || dfs(a, b * c, d) || c && dfs(a, b / c, d)) return true;
		if(dfs(a, b, c + d) || dfs(a, b, c - d) || dfs(a, b, c * d) || d && dfs(a, b, c / d)) return true;

		return false;
	}

	bool dfs(double a, double b, double c){
		if(dfs(a + b, c) || dfs(a - b, c) || dfs(a * b, c) || b && dfs(a / b, c)) return true;
		if(dfs(a, b + c) || dfs(a, b - c) || dfs(a, b * c) || c && dfs(a, b / c)) return true;

		return false;
	}

	bool dfs(double a, double b){
		if( fabs(a + b - 24) < 1e-5 || fabs(a - b - 24) < 1e-5 || fabs(a * b - 24) < 1e-5 || b && fabs(a / b - 24) < 1e-5){
            //cout << a << ' ' << b << endl;
            return true;
        }

		return false;
	}
};

int main(){
    Solution s;
    vector<int> nums {3, 1, 8, 1};
    cout << s.judgePoint24(nums) << endl;
    return 0;
}
