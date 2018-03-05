/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 20:51:59 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        for(int i = 0; i < nums.size() - 1; ++i){
            if( !(i & 1) && nums[i] > nums[i+1])
                swap(nums[i], nums[i+1]);
            if( (i & 1) && nums[i] < nums[i+1])
                swap(nums[i], nums[i+1]);
        }
    }
};

int main(){
    vector<int> nums{3,5,2,1,6,4};
    Solution s;
    s.wiggleSort(nums);
    for(int i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}
