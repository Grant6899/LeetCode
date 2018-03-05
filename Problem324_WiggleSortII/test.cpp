/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 21:14:25 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
            nums[i] = sorted[i&1 ? k++ : j++];
    }
};

int main(){
    Solution s;
    vector<int> nums{1,3,1,1,4,5};
    s.wiggleSort(nums);
    for(int n : nums)
        cout << n << " ";
    cout << endl;
    return 0;
}
