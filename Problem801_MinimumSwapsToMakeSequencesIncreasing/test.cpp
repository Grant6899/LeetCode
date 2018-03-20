/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 19 22:30:33 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<int> notswap(A.size(), 0), swap(A.size(), 1);

		for(int i = 1; i < A.size(); ++i){
			notswap[i] = swap[i] = A.size();

			if(A[i-1] < A[i] && B[i-1] < B[i]){
				notswap[i] = notswap[i-1];
				swap[i] = swap[i-1] + 1;
			}

			if(A[i-1] < B[i] && B[i-1] < A[i]){
				notswap[i] = min(notswap[i], swap[i-1]);
				swap[i] = min(swap[i], notswap[i-1] + 1);
			}
		}
		return min(swap.back(), notswap.back());
    }
};

int main(){
    vector<int> nums1{1, 3, 5, 4}, nums2{1, 2, 3, 7};
    Solution s;
    cout << s.minSwap(nums1, nums2) << endl;
    return 0;
}
