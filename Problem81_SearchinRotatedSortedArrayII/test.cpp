/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Mar  3 13:15:12 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        
        int end = findEnd(nums);
        //cout << "end: " << end << endl;
        int lo = 0, hi = nums.size() - 1;

        if(nums[0] <= target && target <= nums[end])
            hi = end;
        else
            lo = end + 1;

        return search(nums, target, lo, hi);

    }

    bool search(vector<int>& nums, int target, int lo, int hi){
        cout << lo << " " << hi << endl;        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }

    int findEnd(vector<int>& nums){
        if(nums.front() < nums.back())
            return nums.size() - 1;

        int lo = 0, hi = nums.size() - 2;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if( (mid - 1 < 0 || nums[mid - 1] <= nums[mid]) && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[lo] <= nums[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }

};



int main(){
    vector<int> nums{1, 2, 1};
    //vector<int> nums1{1,1,1,1};
    Solution s;
    cout << s.findEnd(nums) << endl;
    //cout << s.search(nums, 2) << endl;
    return 0;
}
