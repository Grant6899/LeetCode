/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Feb 25 11:49:40 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left, right;
        int buffer = 1;
        
        for(int i = 0; i < nums.size(); ++i){
            left.push_back(buffer);
            buffer *= nums[i];
        }
        
        buffer = 1;
        for(int i = nums.size() -1; i >= 0; --i){
            right.push_back(buffer);
            buffer *= nums[i];
        }
        
        reverse(right.begin(), right.end());
        
        vector<int> res;
        
        for(int i = 0; i < nums.size(); ++i){
            res.push_back(left[i] * right[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums {2,3,4,5};
    auto ans = s.productExceptSelf(nums);

    for(int a : ans)
        cout << a << " ";

    cout << endl;
    
    return 0;
}
