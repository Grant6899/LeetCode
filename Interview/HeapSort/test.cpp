/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 15 17:22:20 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& nums, int len, int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < len && nums[i] < nums[left]){
        swap(nums[i], nums[left]);
        heapify(nums, len, left);
    }

    if(right < len && nums[i] < nums[right]){
        swap(nums[i], nums[right]);
        heapify(nums, len, right);
    }
}

void mergesort(vector<int>& nums){
    for(int i = (nums.size() - 1) / 2; i >= 0; --i)
        heapify(nums, nums.size(), i);

    for(int i = (nums.size() - 1); i >= 0; --i){
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

int main(){
    vector<int> nums{3, 9, 6, 1, 8, 7, 4, 2};
    mergesort(nums);
    for(int n : nums)
        cout << n << " ";
    return 0;
}



