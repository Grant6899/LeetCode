/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec 20 19:44:03 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;     
        result.push_back(lowerbound(nums, target));        
        result.push_back(upperbound(nums, target));
        return result;
    }

    int lowerbound(const vector<int>& nums, int target){
        if(nums.empty() || nums.front() > target || nums.back() < target)
            return -1;
        
        if(nums.front() == target)
            return 0;

        int left = 0, right = nums.size() - 1;
        while(left + 1 != right && nums[right] >= target && nums[left] < target){
            int mid = (left + right) / 2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid;
        }
        if(nums[right] == target)
            return right;
        else return -1;
    }

    int upperbound(const vector<int>& nums, int target){
        if(nums.empty() || nums.front() > target || nums.back() < target)
            return -1;
        
        if(nums.back() == target)
            return nums.size() - 1;

        int left = 0, right = nums.size() - 1;
        while(left + 1 != right && nums[right] > target && nums[left] <= target){
            int mid = (left + right) / 2;
            if(nums[mid] > target)
                right = mid;
            else
                left = mid;
        }
        if(nums[left] == target)
            return left;
        else return -1;
    }

};

int main(){
    Solution s;
    vector<int> nums {5, 7, 7, 8, 8, 10};
    auto ans = s.searchRange(nums, 8);

    cout << "[ " << ans[0] <<", " << ans[1] << "]\n";
    return 0;
}
