/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:52:15 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> pool;
		for(int n : nums)
			pool.insert(n);

		int res = 0;
		for(int n : nums){
			if(pool.find(n) == pool.end())
				continue;
			pool.erase(n);
			int prev = n-1, next = n+1;
			while(pool.find(prev) != pool.end()) pool.erase(prev--);
			while(pool.find(next) != pool.end()) pool.erase(next++);
			res = max(res, next - prev - 1);
		}
		return res;
    }
};

int main(){
    vector<int> nums{100, 4, 200, 1, 3, 2};
    Solution s;
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}
