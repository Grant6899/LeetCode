/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 15 17:54:26 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void mergeSort(vector<int>&nums, int l, int mid, int r){
    vector<int> left(nums.begin() + l, nums.begin() + mid + 1), right(nums.begin() + mid + 1, nums.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while(i < left.size() && j < right.size()){
        if(left[i] < right[j]){
            nums[k] = left[i];
            ++i;
        }
        else{
            nums[k] = right[j];
            ++j;
        }
        ++k;
    }

    while(i < left.size()){
        nums[k] = left[i];
        ++i;
        ++k;
    }

    while(j < right.size()){
        nums[k] = right[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& nums, int l, int r){
    if(l == r)
        return;
    int mid = l + (r - l) / 2;
    
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    
    mergeSort(nums, l, mid, r);
}

int main(){
    vector<int> nums{3, 9, 6, 1, 8, 7, 4, 2};

    mergeSort(nums, 0, nums.size() - 1);

    for(int n : nums)
        cout << n << " ";
    cout << endl;
    return 0;
}
