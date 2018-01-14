/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 14 15:59:12 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        find(nums, 0, cur, result);
        return result;
    }

    void find(vector<int>& nums, int idx, vector<int>& cur, vector<vector<int>>& res){
        if( cur.size() > 1)
            res.push_back(cur);

        unordered_set<int> hash;
        for(int i = idx; i < nums.size(); ++i){
            if((cur.empty() || nums[i] >= cur.back()) && hash.find(nums[i]) == hash.end()){
                cur.push_back(nums[i]);
                find(nums, i + 1, cur, res);
                cur.pop_back();
                hash.insert(nums[i]);
            }
        }

    }


};

int main(){
    vector<int> nums {4, 6, 7, 7};
    Solution s;
    auto ans = s.findSubsequences(nums);

    return 0;
}
