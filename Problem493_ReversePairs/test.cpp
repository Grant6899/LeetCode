/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:57:34 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int reversePairs(vector<int>& nums) {
		if(nums.size() <= 1)
			return 0;

        vector<int64_t> numss;

        for(int n : nums)
            numss.push_back(n);

        return mergeSort(numss, 0, nums.size() - 1);
    }

	int mergeSort(vector<int64_t>&nums, int l, int mid, int r){
		vector<int64_t> left(nums.begin() + l, nums.begin() + mid + 1), right(nums.begin() + mid + 1, nums.begin() + r + 1);

		/*cout << "\nleft: ";

		for(int a : left)
			cout << a << " ";

		cout << "\nright: ";
		for(int a : right)
			cout << a << " ";*/

		int ii = 0, jj = 0, kk = l, res = 0;

		while(ii < left.size() && jj < right.size()){
            //cout << "\ncomparing: "<< left[ii] << "  " << right[jj];
			if(left[ii] <= right[jj] * 2){
				++ii;
			}
			else{
				res += left.size() - ii;
              //  cout << "\nres: " << res << endl;
				++jj;
			}
		}

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

		return res;
	}

	int mergeSort(vector<int64_t>& nums, int l, int r){
		if(l >= r)
			return 0;
		int mid = l + (r - l) / 2;

		int res = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, r);

		res += mergeSort(nums, l, mid, r);

		return res;
	}

};
int main(){
    Solution s;
    vector<int> nums{1,3,2,3,1};
    cout << s.reversePairs(nums) << endl;
    return 0;
}
