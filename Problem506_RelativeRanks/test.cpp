/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Dec 28 19:22:22 2017
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        for (int i=0, sz=nums.size();i<sz;i++)
            pq.push({nums[i], i});
        int count = 1;    
        vector<string> res(nums.size());
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            if (count==1)
                res[p.second] = "Gold Medal";
            else if (count==2)
                res[p.second] = "Silver Medal";
            else if (count==3)
                res[p.second] = "Bronze Medal";
            else
                res[p.second] = to_string(count);
            count++;
        }
        return res;
    }
};

int main(){
    vector<int> vec{3,1,4,5,2};
    Solution s;
    auto ans = s.findRelativeRanks(vec);
    return 0;
}
