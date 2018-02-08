/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Feb  6 22:49:53 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size() < 2)
            return false;
        
        if(k == 0){
            for(int i = 0; i < nums.size() - 1; ++i)
                if(nums[i] == 0 && nums[i+1] == 0)
                    return true;
            return false;
        }
            
        k = abs(k);
        unordered_set<int> sum_pool;
        
        sum_pool.insert(0);
        uint32_t sum = 0, prev = 0;

        for(int i = 0;i < nums.size();++i){
            
            sum = (sum + nums[i]) % k;
            if(i >= 1){
                sum_pool.insert(prev);
                if(sum_pool.count(sum))
                    return true;
            }
            prev = sum;
        }
        return false;
    }
};

int main(){

    vector<int> nums {5,2,4};
    Solution s;
    cout << s.checkSubarraySum(nums, 5) << endl;
    return 0;
}

