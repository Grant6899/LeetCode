/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 11 19:43:35 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty())
            return -1;

        long sum = 0, left = 0, right = 0;
        
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        left = 0;
        right = sum - nums[0];
        for (int i = 0; i < nums.size(); ++i){
            if (left == right)
                return i;
            if (i < nums.size() - 1){
                left += nums[i];
                right -= nums[i+1];
            }
            
        }
        
        return -1;
    }
};


int main(){
    vector<int> nums {2, 7, 3, 6, 10, -28, 1};
    Solution s;
    int ans = s.pivotIndex(nums);
    cout << ans << endl;
    return 0;
}
