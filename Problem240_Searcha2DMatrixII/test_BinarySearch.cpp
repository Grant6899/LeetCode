/*************************************************************************
	> File Name: test_BinarySearch.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:33:11 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
		vector<int> first, last;
		
		for(int i = 0; i < matrix.size(); ++i){
			first.push_back(matrix[i].front());
			last.push_back(matrix[i].back());
		}
		
		int up_idx = upper_bound(first.begin(), first.end(), target) - first.begin();
		int low_idx = lower_bound(last.begin(), last.end(), target) - last.begin();
	
		for(int i = low_idx; i < up_idx; ++i){
			if(bs(matrix[i], target))
				return true;
		}
		return false;
    }
	
	bool bs(vector<int>& nums, int target){
		
		int left = 0, right = nums.size() - 1;

		while(left <= right){
			int mid = left  + (right - left) / 2;
			//cout << nums[left] << " " << nums[right] << endl;
			if(nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid - 1;
			else
				return true;
		}
		return false;
	}
	
};

int main(){
    Solution s;
    vector<vector<int>> nums{
  {1,   4,  7, 11, 15},
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}
};
	cout << s.searchMatrix(nums, 5) << endl;
    return 0;
}
