/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Mar  3 11:55:40 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int BinarySearch(vector<int>& nums, int target){
    int lo = 0, hi = nums.size() - 1;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

// find the first element in the array that is strictly greater than target
int upperBound(vector<int>& nums, int target){
    int lo = 0, hi = nums.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(nums[mid] <= target)
            lo = mid + 1;
        else
            hi = mid -1;
    }
    return lo;
}

// find the first element in the array that is strictly greater than or equal to target
int lowerBound(vector<int>& nums, int target){
    int lo = 0, hi = nums.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid -1;
    }
    return lo;
}

int main(){
    vector<int> nums{3, 5, 6, 9, 13, 19, 20, 33, 45, 47};
        
    cout << "Accurate search: " << BinarySearch(nums, 13) << endl;
    cout << "Upperbound: " << upperBound(nums, 19) << endl;
    cout << "Lowerbound: " << lowerBound(nums, 19) << endl;
    return 0;

}
