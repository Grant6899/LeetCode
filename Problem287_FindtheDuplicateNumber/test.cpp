/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 10 21:06:22 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> pool;

        for(int i = 0; i < nums.size(); ++i){
            if (pool.find(nums[i]) == pool.end())
                pool.insert(nums[i]);
            else
                return nums[i];
        }
        return 0;
    }
};

int main(){
    vector<int> nums {1,2,3,4,2};

    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}
