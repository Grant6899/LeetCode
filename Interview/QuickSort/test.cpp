/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Apr  5 18:57:37 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int>& nums, int left, int right){

    int i = left, j = right;
    int pivot = nums[left + (right - left) / 2];

    while(i <= j){
        
        while(nums[i] < pivot) i++;
        while(nums[j] > pivot) j--;

        if(i <= j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    
    if(left < j) quicksort(nums, left, j);
    if(i < right) quicksort(nums, i, right);

}


int main(){
    vector<int> nums{1, 12, 5, 26, 7, 14, 3, 7, 2};
    
    quicksort(nums, 0, nums.size() - 1);

    for(int n : nums)
        cout << n << " ";
    cout << endl;
    return 0;
}

